#pragma once
#include "TScanTable.h"

//Для изменения режима сортировки
enum class TSortingMode { QUICK_SORT, SELECTION_SORT };
TSortingMode T_SORTING_MODE;

/* Упорядоченная таблица (по ключам) */
class TSortTable : public TScanTable
{
public:
	TSortTable(int _size = 10);
	TSortTable(TScanTable& st);

	bool Find(TKey key);
	bool Insert(TRecord rec);
	bool Delete(TKey key);

private:
	void QuickSort(int first, int last);
	void SelectionSort();
	void Sort();
};

TSortTable::TSortTable(int _size) : TScanTable(_size) { }

TSortTable::TSortTable(TScanTable& st) : TScanTable(st.GetSize())
{
	//Копирование всех записей из TScanTable в текущую таблицу
	//В их исходном порядке
	DataCount = st.GetDataCount();
	int i;
	for (i = 0, st.Reset(); !st.IsEnd(); st.GoNext(), i++)
	{
		arr[i] = TRecord(st.GetCurrentKey(), st.GetCurrentVal());
		Eff++;
	}
	//Сортировка элементов текущей таблицы
	Sort();
}

bool TSortTable::Find(TKey key)
{
	int begin = 0, end = DataCount - 1;
	int mid;

	while (begin <= end)
	{
		Eff++;

		mid = (begin + end) / 2;

		//Ключ левее
		if (key < arr[mid].key)
			end = mid - 1;
		//Ключ правее
		else if (key > arr[mid].key)
			begin = mid + 1;
		//Нашли (key == arr[mid].key)
		else
		{
			//curr ставим куда нужно
			curr = mid;
			return true;
		}
	}
	//Не нашли - нужно поставить curr туда, куда элемент мог бы быть добавлен
	//(вроде бы это правильно, но всё же требует тестирования)
	curr = begin;
	return false;
}

bool TSortTable::Insert(TRecord rec)
{
	//Если таблица полна - вставить некуда
	if (IsFull())
		throw "Can't insert: no more space in table";

	//Если запись с таким ключом уже есть - вставка невозможна
	if (Find(rec.key))
		return false;

	//Добавим элемент на позицию curr, ранее подсказанную Find.
	//Т. е. сместим все элементы справа от этой позиции вправо
	for (int i = DataCount - 1; i >= curr; i--)
	{
		Eff++;
		arr[i + 1] = arr[i];
	}
	//И вставим элемент
	Eff++;
	arr[curr] = rec;
	DataCount++;
	return true;
}

bool TSortTable::Delete(TKey key)
{
	if (Find(key))
	{
		//Удалим элемент с позиции curr, ранее подсказанной Find.
		//Т. е. сместим все элементы справа от этой позиции влево
		//Пример: [][][curr][curr+1][]...[][][DataCount - 1]...[]
		for (int i = curr + 1; i <= DataCount - 1; i++)
		{
			Eff++;
			arr[i - 1] = arr[i];
		}
		DataCount--;
		return true;
	}
	else return false;
}

//Быстрая сортировка (алг. сложность в среднем O(n*ln n))
//first, last - индексы в массиве arr
void TSortTable::QuickSort(int first, int last)
{
	//TODO переименовать в midKey
	TKey midKey = arr[(first + last) / 2].key;

	int f = first, l = last;
	while (f < l)
	{
		while (arr[f].key < midKey)
		{
			f++;
			Eff++;
		}
		while (arr[l].key > midKey)
		{
			l--;
			Eff++;
		}

		//Если индексы не зашли друг за друга
		if (f <= l)
		{
			std::swap(arr[f], arr[l]);
			f++; l--;
			Eff++;
		}
	}

	//Если осталось что-то слева
	if (first < l)
		QuickSort(first, l);
	//Если осталось что-то справа
	if (last > f)
		QuickSort(f, last);
}

//Сортировка выбором (алг. сложность O(n^2))
void TSortTable::SelectionSort()
{
	int pos;

	for (int i = 0; i < DataCount; i++)
	{
		pos = i;
		//Нахождение позиции минимального эл-та в неотсортированной части массива
		for (int j = i; j < DataCount; j++)
		{
			Eff++;
			if (arr[j].key < arr[pos].key)
				pos = j;
		}
		//Перемещение минимального эл-та в конец отсортированной части
		std::swap(arr[pos], arr[i]);
		Eff++;
	}
}

void TSortTable::Sort()
{
	if (T_SORTING_MODE == TSortingMode::QUICK_SORT)
		QuickSort(0, DataCount - 1);
	else if (T_SORTING_MODE == TSortingMode::SELECTION_SORT)
		SelectionSort();
}