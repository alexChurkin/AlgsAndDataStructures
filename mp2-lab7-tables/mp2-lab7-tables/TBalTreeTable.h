#pragma once
#include "TTreeTable.h"

//В итоге ф-я балансировки должна принять балансируемую вершину
//И вернуть результатом одну из этих констант
//Константа, соответствующая тому, что глубина (т.е. высота) не изменилась
const int H_OK = 0;
//Константа, соответствующая тому, что глубина увеличилась на 1
const int H_INC = 1;
//Константа, соответствующая тому, что глубина уменьшилась на 1
const int H_DEC = -1;

/* Таблица на сбалансированном дереве */
class TBalTreeTable : public TTreeTable
{
private:
	//Вспомогательные методы для балансировки при добавлении
	int LeftBalance(TTreeNode*& p);
	int RightBalance(TTreeNode*& p);
	//Вставка в поддерево с балансировкой (корень p поддерева может измениться)
	int InsertBalance(TTreeNode*& p, TRecord rec);

	//Поиск максимального элемента в поддереве с корнем pl
	TTreeNode* FindMax(TTreeNode* pl);
	//Исключение максимального элемента в поддереве с корнем pl
	int RemoveMax(TTreeNode*& pl);

	//Вспомогательные методы для балансировки при удалении
	int LeftBalanceDel(TTreeNode*& p);
	int RightBalanceDel(TTreeNode*& p);
	//удаление из поддерева с балансировкой (корень P поддерева может измениться)
	int DeleteBalance(TTreeNode*& p, TKey key);

public:
	bool Insert(TRecord rec) override;

	bool Delete(TKey key) override;
};

//После балансировки корень поддерева может поменяться, поэтому
//передаём ссылку на указатель!
int TBalTreeTable::LeftBalance(TTreeNode*& p)
{
	int result = H_OK;

	//1. В звене p был перевес на 1 вправо, но исчез
	if (p->Bal == 1)
	{
		p->Bal = 0;
		result = H_OK;
	}
	//2. В звене p не было перевеса, и появился перевес на 1 влево
	else if (p->Bal == 0)
	{
		p->Bal = -1;
		result = H_INC;
	}
	//3. В звене p возник недопустимый перевес слева
	else
	{
		TTreeNode* pl = p->pLeft;

		//3.1. Перевес возник вследствие утяжеления левого звена слева
		if (pl->Bal == -1)
		{
			p->pLeft = pl->pRight;
			pl->pRight = p;

			pl->Bal = 0;
			p->Bal = 0;

			p = pl;
			result = H_OK;
		}
		//3.2. Перевес возник вследствие утяжеления левого звена справа
		else if (pl->Bal == 1)
		{
			TTreeNode* plpr = pl->pRight;

			pl->pRight = plpr->pLeft;
			plpr->pLeft = pl;
			p->pLeft = plpr->pRight;
			plpr->pRight = p;
			if (plpr->Bal == -1)
				p->Bal = 1;
			else
				p->Bal = 0;
			if (plpr->Bal == 1)
				pl->Bal = -1;
			else
				pl->Bal = 0;
			p = plpr;
			p->Bal = 0;
			result = H_OK;
		}
	}
	return result;
}

int TBalTreeTable::RightBalance(TTreeNode*& p)
{
	int result = H_OK;

	//1. В звене p был перевес на 1 влево, но исчез
	if (p->Bal == -1)
	{
		p->Bal = 0;
		result = H_OK;
	}
	//2. В звене p не было перевеса, и появился перевес на 1 вправо
	else if (p->Bal == 0)
	{
		p->Bal = 1;
		result = H_INC;
	}
	//3. В звене p возник недопустимый перевес справа
	else
	{
		TTreeNode* pr = p->pRight;

		//3.1. Перевес возник вследствие утяжеления правого звена справа
		if (pr->Bal == 1)
		{
			p->pRight = pr->pLeft;
			pr->pLeft = p;

			pr->Bal = 0;
			p->Bal = 0;

			p = pr;
			result = H_OK;
		}
		//3.2. Перевес возник вследствие утяжеления правого звена слева
		else if (pr->Bal == -1)
		{
			TTreeNode* prpl = pr->pLeft;

			pr->pLeft = prpl->pRight;
			prpl->pRight = pr;
			p->pRight = prpl->pLeft;
			prpl->pLeft = p;
			if (prpl->Bal == 1)
				p->Bal = -1;
			else
				p->Bal = 0;
			if (prpl->Bal == -1)
				pr->Bal = 1;
			else
				pr->Bal = 0;
			p = prpl;
			p->Bal = 0;
			result = H_OK;
		}
	}
	return result;
}

//Вставка звена с записью в поддерево с попутной его балансировкой.
//Принимает указатель на звено по ссылке,
//чтобы он сразу изменялся и для предыдущего звена
int TBalTreeTable::InsertBalance(TTreeNode*& p, TRecord rec)
{
	Eff++;

	//Результат работы функции - изменение балансировки в поддереве
	int result = H_OK;

	//Конец рекурсии (спуска вниз) - достижение нулевого указателя
	if (p == nullptr)
	{
		//Подцепляется новое звено, и наверх отправляется сигнал об увеличении высоты
		p = new TTreeNode(rec);
		result = H_INC;
		DataCount++;
	}
	//Добавляемая запись имеет значение ключа меньше,
	//чем значение ключа записи у звена, на которое мы смотрим
	else if (rec.key < p->rec.key)
	{
		//Рекурсивно отправляемся влево вниз по дереву
		int tmp = InsertBalance(p->pLeft, rec);

		//Если добавление звена привело к увеличению высоты в левом поддереве,
		//необходимо выполнить проверку, а возможно и исправление балансировки слева
		if (tmp == H_INC)
			result = LeftBalance(p);
	}
	//Добавляемая запись имеет значение ключа больше,
	//чем значение ключа записи у звена, на которое мы смотрим
	else /*if (rec.key > p->rec.key)*/
	{
		//Рекурсивно отправляемся вправо вниз по дереву
		int tmp = InsertBalance(p->pRight, rec);

		//Если добавление звена привело к увеличению высоты в правом поддереве,
		//необходимо выполнить проверку, а возможно и исправление балансировки справа
		if (tmp == H_INC)
			result = RightBalance(p);
	}

	return result;
}



TTreeNode* TBalTreeTable::FindMax(TTreeNode* pl)
{
	TTreeNode* pRes = pl;
	while (pRes->pRight != nullptr)
	{
		Eff++;
		pRes = pRes->pRight;
	}
	return pRes;
}

//Исключение максимального звена из дерева без удаления
int TBalTreeTable::RemoveMax(TTreeNode*& pl)
{
	Eff++;
	int result;
	if (pl->pRight == nullptr)
	{
		pl = pl->pLeft;
		result = H_DEC;
	}
	else
	{
		result = RemoveMax(pl->pRight);
		//Если у правого поддерева уменьшилась высота, нужна балансировка слева
		if (result == H_DEC)
			result = LeftBalanceDel(pl);
	}
	return result;
}

int TBalTreeTable::LeftBalanceDel(TTreeNode*& p)
{
	int result = H_OK;

	//1. В звене p был перевес на 1 вправо, но исчез
	if (p->Bal == 1)
	{
		p->Bal = 0;
		result = H_DEC;
	}
	//2. В звене p не было перевеса, и появился перевес на 1 влево
	else if (p->Bal == 0)
	{
		p->Bal = -1;
		//ПОМЕНЯЛ
		result = H_OK;
	}
	//3. В звене p возник недопустимый перевес слева
	else
	{
		TTreeNode* pl = p->pLeft;

		//3.1. Перевес возник вследствие облегчения левого звена справа
		if (pl->Bal == -1)
		{
			p->pLeft = pl->pRight;
			pl->pRight = p;

			pl->Bal = 0;
			p->Bal = 0;

			p = pl;
			result = H_DEC;
		}
		//3.2. Перевес возник вследствие облегчения левого звена слева
		else if (pl->Bal == 1)
		{
			TTreeNode* plpr = pl->pRight;

			pl->pRight = plpr->pLeft;
			plpr->pLeft = pl;
			p->pLeft = plpr->pRight;
			plpr->pRight = p;
			if (plpr->Bal == -1)
				p->Bal = 1;
			else
				p->Bal = 0;
			if (plpr->Bal == 1)
				pl->Bal = -1;
			else
				pl->Bal = 0;
			p = plpr;
			p->Bal = 0;
			result = H_DEC;
		}
		//3.3. Перевес возник, и левое звено имеет 2-х потомков (новый случай)
		else
		{
			TTreeNode* pp = p;
			//TTreeNode* pl = pl;
			TTreeNode* plpl = pl->pLeft;
			TTreeNode* plpr = pl->pRight;

			//Установка pl корнем поддерева и перестановки указателей
			p = pl;
			p->pLeft = plpl;
			p->pRight = pp;
			pp->pLeft = plpr;
			pl->Bal = 1;
			return H_OK;
		}
	}
	return result;
}

int TBalTreeTable::RightBalanceDel(TTreeNode*& p)
{
	int result = H_OK;

	//1. В звене p был перевес на 1 влево, но исчез
	if (p->Bal == -1)
	{
		p->Bal = 0;
		result = H_DEC;
	}
	//2. В звене p не было перевеса, и появился перевес на 1 вправо
	else if (p->Bal == 0)
	{
		p->Bal = 1;
		result = H_OK;
	}
	//3. В звене p возник недопустимый перевес справа
	else
	{
		TTreeNode* pr = p->pRight;

		//3.1. Перевес возник вследствие облегчения правого звена слева
		if (pr->Bal == 1)
		{
			p->pRight = pr->pLeft;
			pr->pLeft = p;

			pr->Bal = 0;
			p->Bal = 0;

			p = pr;
			result = H_DEC;
		}
		//3.2. Перевес возник вследствие облегчения правого звена справа
		else if (pr->Bal == -1)
		{
			TTreeNode* prpl = pr->pLeft;

			pr->pLeft = prpl->pRight;
			prpl->pRight = pr;
			p->pRight = prpl->pLeft;
			prpl->pLeft = p;
			if (prpl->Bal == 1)
				p->Bal = -1;
			else
				p->Bal = 0;
			if (prpl->Bal == -1)
				pr->Bal = 1;
			else
				pr->Bal = 0;
			p = prpl;
			p->Bal = 0;
			result = H_DEC;
		}
		//3.3. Перевес возник, и правое звено имеет 2-х потомков (новый случай)
		else
		{
			TTreeNode* pp = p;
			//TTreeNode* pr = pr;
			TTreeNode* prpl = pr->pLeft;
			TTreeNode* prpr = pr->pRight;

			//Установка pr корнем поддерева и перестановки указателей
			p = pr;
			p->pLeft = pp;
			p->pRight = prpr;
			pp->pRight = prpl;
			pr->Bal = -1;
			return H_OK;
		}
	}
	return result;
}

int TBalTreeTable::DeleteBalance(TTreeNode*& p, TKey key)
{
	Eff++;

	int result = H_OK;
	int tmp;

	//Ключ искомой записи имеет значение меньше,
	//чем значение ключа записи у звена, на которое мы смотрим
	if (key < p->rec.key)
	{
		//Отправляемся рекурсивно влево вниз
		tmp = DeleteBalance(p->pLeft, key);
		if (tmp != H_OK)
			result = RightBalanceDel(p);
	}
	//Ключ искомой записи имеет значение больше,
	//чем значение ключа записи у звена, на которое мы смотрим
	else if (key > p->rec.key)
	{
		//Отправляемся рекурсивно вправо вниз
		tmp = DeleteBalance(p->pRight, key);
		if (tmp != H_OK)
			result = LeftBalanceDel(p);
	}
	//Звено с искомым ключом найдено
	else /*if(p->rec.key == key)*/
	{
		//У него нет потомков
		if (p->pLeft == nullptr && p->pRight == nullptr)
		{
			//Тогда он просто физически удаляется, и наверх сообщается уменьшение высоты
			delete p;
			p = nullptr;
			result = H_DEC;
		}
		//У него один потомок - слева (у p показатель балансировки -1)
		else if (p->pLeft != nullptr && p->pRight == nullptr)
		{
			//Берём запись слева и переписываем её в наше звено p
			p->rec = p->pLeft->rec;
			
			//Старое левое звено удаляется физически
			delete p->pLeft;
			p->pLeft = nullptr;

			//Обновляется балансировка - ставим 0 (т.к. удалили слева лист)
			p->Bal = 0;
			//Наверх сообщается об уменьшении высоты
			result = H_DEC;
		}
		//У него один потомок - справа (у p показатель балансировки 1)
		else if (p->pLeft == nullptr && p->pRight != nullptr)
		{
			//Берём запись справа и переписываем её в наше звено p
			p->rec = p->pRight->rec;

			//Старое правое звено удаляется физически
			delete p->pRight;
			p->pRight = nullptr;

			//Обновляется балансировка - ставим 0 (т.к. удалили справа лист)
			p->Bal = 0;
			//Наверх сообщается об уменьшении высоты
			result = H_DEC;
		}
		else
		{
			TTreeNode* pl = p->pLeft;
			//Найдём максимальную вершину в правом поддереве p
			TTreeNode* pMax = FindMax(p->pLeft);
			//Исключение из дерева этой вершины
			tmp = RemoveMax(pl);
			//И её физическое удаление
			p->rec = pMax->rec;
			delete pMax;
			pMax = nullptr;

			//Теперь к p подвешивается слева то, что получилось (pl мог поменяться после RemoveMax)
			p->pLeft = pl;

			if (tmp != H_OK)
				result = RightBalanceDel(p);
		}
		DataCount--;
	}

	return result;
}



bool TBalTreeTable::Insert(TRecord rec)
{
	if (IsFull()) throw "Can't insert: no more space in table";
	if (Find(rec.key)) return false;
	//Вызов вставки с попутной автоматической балансировкой
	//InsertBalance может и сменить корень дерева,
	//поэтому указатель на корень передаётся по ссылке
	InsertBalance(pRoot, rec);
	return true;
}

bool TBalTreeTable::Delete(TKey key)
{
	if (!Find(key)) return false;

	DeleteBalance(pRoot, key);
	return true;
}