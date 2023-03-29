#pragma once
#include "TTable.h"

class THashTable : public TTable
{
//Здесь вычисляется начальный вариант хэш-функции
protected:
	//virtual затем, что это как бы начальная реализация хэш-функции
	//(самая простая)
	virtual int HashFunc(TKey key) const
	{
		return key;
	}
};