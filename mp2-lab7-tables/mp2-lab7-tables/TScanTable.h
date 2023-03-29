#pragma once
#include "TArrayTable.h"

/* Неупорядоченная таблица (таблица прямого поиска). */
class TScanTable : public TArrayTable
{
public:
	TScanTable(int _size = 10);

	bool Find(TKey key);
	bool Insert(TRecord rec);
	bool Delete(TKey key);
};

TScanTable::TScanTable(int _size) : TArrayTable(_size) { }

bool TScanTable::Find(TKey key)
{
	for (int i = 0; i < DataCount; i++)
	{
		//Каждое действие - плюс к эффективности
		Eff++;
		if (arr[i].key == key)
		{
			//Если нашли - как текущий устанавливаем его
			curr = i;
			return true;
		}
	}
	//Если не нашли - как текущий устанавливаем то место,
	//куда бы гипотетически он мог быть добавлен
	curr = DataCount;
	return false;
}

bool TScanTable::Insert(TRecord rec)
{
	//Если таблица полна - вставить некуда
	if (IsFull())
		throw "Can't insert: no more space in table";

	//Если запись с таким ключом уже есть - вставка невозможна
	if (Find(rec.key))
		return false;

	arr[DataCount] = rec;
	DataCount++;

	Eff++;
	return true;
}

bool TScanTable::Delete(TKey key)
{
	if (Find(key))
	{
		arr[curr] = arr[DataCount - 1];
		DataCount--;
		Eff++;
		return true;
	}
	else return false;
}