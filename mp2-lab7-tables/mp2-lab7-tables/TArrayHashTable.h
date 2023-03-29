#pragma once
#include "THashTable.h"

class TArrayHashTable : public THashTable
{
private:
	TRecord Free, Deleted;
protected:
	TRecord* arr;
	int size;
	//Шаг при хэшировании (на этот шаг будет переход при коллизиях)
	int step;

	//Номер текущего элемента
	int curr;

public:
	//Шаг должен быть взаимно простым с размером
	TArrayHashTable(int _size = 10, int _step = 3);
	~TArrayHashTable();

	bool IsFull() const override;

	bool Find(TKey key) override;
	bool Insert(TRecord rec) override;
	bool Delete(TKey key) override;

	void Reset() override;
	void GoNext() override;
	bool IsEnd() override;

	TKey GetCurrentKey() const override;
	TValue GetCurrentVal() const override;
};

TArrayHashTable::TArrayHashTable(int _size, int _step)
{
	size = _size;
	step = _step;
	arr = new TRecord[size];

	Free.key = -1;
	Deleted.key = -2;

	//В начале работы "говорим, что все записи не заняты"
	for (int i = 0; i < size; i++)
		arr[i] = Free;
}

TArrayHashTable::~TArrayHashTable()
{
	delete[] arr;
}

bool TArrayHashTable::IsFull() const
{
	return (DataCount == size);
}

bool TArrayHashTable::Find(TKey key)
{
	//Если fl == -1 - не было встречено ни одной строки с удалённой записью; fl == 1 - уже была
	int fl = -1;
	int pos = HashFunc(key) % size;
	
	for (int i = 0; i < size; i++)
	{
		Eff++;
		//По значению хэш-функции сразу найдена строка с записью, имеющей ключ key
		if (arr[pos].key == key)
		{
			curr = pos;
			return true;
		}
		//Если строка содержит удалённую запись,
		//и это первая встреченная строка с удалённой записью (fl == -1),
		//необходимо запомнить её позицию.
		//После строки с удалённой записью может быть встречена и строка с искомой, но
		//если этого не произойдёт, curr укажет на строку с первой удалённой записью
		//для вставки на это место в будущем.
		else if (arr[pos] == Deleted && fl == -1)
		{
			curr = pos;
			fl = 1;
		}
		//Встречена свободная строка. Следовательно, запись с ключом key
		//отсутствует в таблице.
		else if (arr[pos] == Free)
		{
			//До этого не была встречена ни одна строка с удалённой записью.
			//Значит, на строку с индексом pos можно будет вставить будущую новую запись.
			if (fl == -1)
				curr = pos;
			break;
		}

		pos = (pos + step) % size;
	}
	return false;
}

bool TArrayHashTable::Insert(TRecord rec)
{
	if (IsFull())
		throw "Can't insert: no more space in table";
	if (Find(rec.key))
		return false;
	arr[curr] = rec;
	DataCount++;
	Eff++;
	return true;
}

bool TArrayHashTable::Delete(TKey key)
{
	if (IsEmpty())
		return false;
	if (Find(key))
	{
		arr[curr] = Deleted;
		DataCount--;
		Eff++;
		return true;
	}
	return false;
}

void TArrayHashTable::Reset()
{
	//Reset ставит curr на первую занятую (не свободную и не удалённую) строку
	for (curr = 0; curr < size; curr++)
		if (arr[curr] != Free && arr[curr] != Deleted)
			return;
}

void TArrayHashTable::GoNext()
{
	//Проход от текущей занятой строки до следующей
	//занятой строки таблицы
	for (curr++; curr < size; curr++)
		if (arr[curr] != Free && arr[curr] != Deleted)
			return;
	//В конце цикла, если мы дошли до конца таблицы и не нашли занятых строк,
	//то curr будет == size
}

bool TArrayHashTable::IsEnd()
{
	//Проверка на достижение конца таблицы
	return (curr == size);
}

TKey TArrayHashTable::GetCurrentKey() const
{
	return arr[curr].key;
}

TValue TArrayHashTable::GetCurrentVal() const
{
	return arr[curr].val;
}