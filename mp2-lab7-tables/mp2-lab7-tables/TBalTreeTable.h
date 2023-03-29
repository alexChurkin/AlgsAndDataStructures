#pragma once
#include "TTreeTable.h"

//� ����� �-� ������������ ������ ������� ������������� �������
//� ������� ����������� ���� �� ���� ��������
//���������, ��������������� ����, ��� ������� (�.�. ������) �� ����������
const int H_OK = 0;
//���������, ��������������� ����, ��� ������� ����������� �� 1
const int H_INC = 1;
//���������, ��������������� ����, ��� ������� ����������� �� 1
const int H_DEC = -1;

/* ������� �� ���������������� ������ */
class TBalTreeTable : public TTreeTable
{
private:
	//��������������� ������ ��� ������������ ��� ����������
	int LeftBalance(TTreeNode*& p);
	int RightBalance(TTreeNode*& p);
	//������� � ��������� � ������������� (������ p ��������� ����� ����������)
	int InsertBalance(TTreeNode*& p, TRecord rec);

	//����� ������������� �������� � ��������� � ������ pl
	TTreeNode* FindMax(TTreeNode* pl);
	//���������� ������������� �������� � ��������� � ������ pl
	int RemoveMax(TTreeNode*& pl);

	//��������������� ������ ��� ������������ ��� ��������
	int LeftBalanceDel(TTreeNode*& p);
	int RightBalanceDel(TTreeNode*& p);
	//�������� �� ��������� � ������������� (������ P ��������� ����� ����������)
	int DeleteBalance(TTreeNode*& p, TKey key);

public:
	bool Insert(TRecord rec) override;

	bool Delete(TKey key) override;
};

//����� ������������ ������ ��������� ����� ����������, �������
//������� ������ �� ���������!
int TBalTreeTable::LeftBalance(TTreeNode*& p)
{
	int result = H_OK;

	//1. � ����� p ��� ������� �� 1 ������, �� �����
	if (p->Bal == 1)
	{
		p->Bal = 0;
		result = H_OK;
	}
	//2. � ����� p �� ���� ��������, � �������� ������� �� 1 �����
	else if (p->Bal == 0)
	{
		p->Bal = -1;
		result = H_INC;
	}
	//3. � ����� p ������ ������������ ������� �����
	else
	{
		TTreeNode* pl = p->pLeft;

		//3.1. ������� ������ ���������� ���������� ������ ����� �����
		if (pl->Bal == -1)
		{
			p->pLeft = pl->pRight;
			pl->pRight = p;

			pl->Bal = 0;
			p->Bal = 0;

			p = pl;
			result = H_OK;
		}
		//3.2. ������� ������ ���������� ���������� ������ ����� ������
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

	//1. � ����� p ��� ������� �� 1 �����, �� �����
	if (p->Bal == -1)
	{
		p->Bal = 0;
		result = H_OK;
	}
	//2. � ����� p �� ���� ��������, � �������� ������� �� 1 ������
	else if (p->Bal == 0)
	{
		p->Bal = 1;
		result = H_INC;
	}
	//3. � ����� p ������ ������������ ������� ������
	else
	{
		TTreeNode* pr = p->pRight;

		//3.1. ������� ������ ���������� ���������� ������� ����� ������
		if (pr->Bal == 1)
		{
			p->pRight = pr->pLeft;
			pr->pLeft = p;

			pr->Bal = 0;
			p->Bal = 0;

			p = pr;
			result = H_OK;
		}
		//3.2. ������� ������ ���������� ���������� ������� ����� �����
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

//������� ����� � ������� � ��������� � �������� ��� �������������.
//��������� ��������� �� ����� �� ������,
//����� �� ����� ��������� � ��� ����������� �����
int TBalTreeTable::InsertBalance(TTreeNode*& p, TRecord rec)
{
	Eff++;

	//��������� ������ ������� - ��������� ������������ � ���������
	int result = H_OK;

	//����� �������� (������ ����) - ���������� �������� ���������
	if (p == nullptr)
	{
		//������������ ����� �����, � ������ ������������ ������ �� ���������� ������
		p = new TTreeNode(rec);
		result = H_INC;
		DataCount++;
	}
	//����������� ������ ����� �������� ����� ������,
	//��� �������� ����� ������ � �����, �� ������� �� �������
	else if (rec.key < p->rec.key)
	{
		//���������� ������������ ����� ���� �� ������
		int tmp = InsertBalance(p->pLeft, rec);

		//���� ���������� ����� ������� � ���������� ������ � ����� ���������,
		//���������� ��������� ��������, � �������� � ����������� ������������ �����
		if (tmp == H_INC)
			result = LeftBalance(p);
	}
	//����������� ������ ����� �������� ����� ������,
	//��� �������� ����� ������ � �����, �� ������� �� �������
	else /*if (rec.key > p->rec.key)*/
	{
		//���������� ������������ ������ ���� �� ������
		int tmp = InsertBalance(p->pRight, rec);

		//���� ���������� ����� ������� � ���������� ������ � ������ ���������,
		//���������� ��������� ��������, � �������� � ����������� ������������ ������
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

//���������� ������������� ����� �� ������ ��� ��������
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
		//���� � ������� ��������� ����������� ������, ����� ������������ �����
		if (result == H_DEC)
			result = LeftBalanceDel(pl);
	}
	return result;
}

int TBalTreeTable::LeftBalanceDel(TTreeNode*& p)
{
	int result = H_OK;

	//1. � ����� p ��� ������� �� 1 ������, �� �����
	if (p->Bal == 1)
	{
		p->Bal = 0;
		result = H_DEC;
	}
	//2. � ����� p �� ���� ��������, � �������� ������� �� 1 �����
	else if (p->Bal == 0)
	{
		p->Bal = -1;
		//�������
		result = H_OK;
	}
	//3. � ����� p ������ ������������ ������� �����
	else
	{
		TTreeNode* pl = p->pLeft;

		//3.1. ������� ������ ���������� ���������� ������ ����� ������
		if (pl->Bal == -1)
		{
			p->pLeft = pl->pRight;
			pl->pRight = p;

			pl->Bal = 0;
			p->Bal = 0;

			p = pl;
			result = H_DEC;
		}
		//3.2. ������� ������ ���������� ���������� ������ ����� �����
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
		//3.3. ������� ������, � ����� ����� ����� 2-� �������� (����� ������)
		else
		{
			TTreeNode* pp = p;
			//TTreeNode* pl = pl;
			TTreeNode* plpl = pl->pLeft;
			TTreeNode* plpr = pl->pRight;

			//��������� pl ������ ��������� � ������������ ����������
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

	//1. � ����� p ��� ������� �� 1 �����, �� �����
	if (p->Bal == -1)
	{
		p->Bal = 0;
		result = H_DEC;
	}
	//2. � ����� p �� ���� ��������, � �������� ������� �� 1 ������
	else if (p->Bal == 0)
	{
		p->Bal = 1;
		result = H_OK;
	}
	//3. � ����� p ������ ������������ ������� ������
	else
	{
		TTreeNode* pr = p->pRight;

		//3.1. ������� ������ ���������� ���������� ������� ����� �����
		if (pr->Bal == 1)
		{
			p->pRight = pr->pLeft;
			pr->pLeft = p;

			pr->Bal = 0;
			p->Bal = 0;

			p = pr;
			result = H_DEC;
		}
		//3.2. ������� ������ ���������� ���������� ������� ����� ������
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
		//3.3. ������� ������, � ������ ����� ����� 2-� �������� (����� ������)
		else
		{
			TTreeNode* pp = p;
			//TTreeNode* pr = pr;
			TTreeNode* prpl = pr->pLeft;
			TTreeNode* prpr = pr->pRight;

			//��������� pr ������ ��������� � ������������ ����������
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

	//���� ������� ������ ����� �������� ������,
	//��� �������� ����� ������ � �����, �� ������� �� �������
	if (key < p->rec.key)
	{
		//������������ ���������� ����� ����
		tmp = DeleteBalance(p->pLeft, key);
		if (tmp != H_OK)
			result = RightBalanceDel(p);
	}
	//���� ������� ������ ����� �������� ������,
	//��� �������� ����� ������ � �����, �� ������� �� �������
	else if (key > p->rec.key)
	{
		//������������ ���������� ������ ����
		tmp = DeleteBalance(p->pRight, key);
		if (tmp != H_OK)
			result = LeftBalanceDel(p);
	}
	//����� � ������� ������ �������
	else /*if(p->rec.key == key)*/
	{
		//� ���� ��� ��������
		if (p->pLeft == nullptr && p->pRight == nullptr)
		{
			//����� �� ������ ��������� ���������, � ������ ���������� ���������� ������
			delete p;
			p = nullptr;
			result = H_DEC;
		}
		//� ���� ���� ������� - ����� (� p ���������� ������������ -1)
		else if (p->pLeft != nullptr && p->pRight == nullptr)
		{
			//���� ������ ����� � ������������ � � ���� ����� p
			p->rec = p->pLeft->rec;
			
			//������ ����� ����� ��������� ���������
			delete p->pLeft;
			p->pLeft = nullptr;

			//����������� ������������ - ������ 0 (�.�. ������� ����� ����)
			p->Bal = 0;
			//������ ���������� �� ���������� ������
			result = H_DEC;
		}
		//� ���� ���� ������� - ������ (� p ���������� ������������ 1)
		else if (p->pLeft == nullptr && p->pRight != nullptr)
		{
			//���� ������ ������ � ������������ � � ���� ����� p
			p->rec = p->pRight->rec;

			//������ ������ ����� ��������� ���������
			delete p->pRight;
			p->pRight = nullptr;

			//����������� ������������ - ������ 0 (�.�. ������� ������ ����)
			p->Bal = 0;
			//������ ���������� �� ���������� ������
			result = H_DEC;
		}
		else
		{
			TTreeNode* pl = p->pLeft;
			//����� ������������ ������� � ������ ��������� p
			TTreeNode* pMax = FindMax(p->pLeft);
			//���������� �� ������ ���� �������
			tmp = RemoveMax(pl);
			//� � ���������� ��������
			p->rec = pMax->rec;
			delete pMax;
			pMax = nullptr;

			//������ � p ������������� ����� ��, ��� ���������� (pl ��� ���������� ����� RemoveMax)
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
	//����� ������� � �������� �������������� �������������
	//InsertBalance ����� � ������� ������ ������,
	//������� ��������� �� ������ ��������� �� ������
	InsertBalance(pRoot, rec);
	return true;
}

bool TBalTreeTable::Delete(TKey key)
{
	if (!Find(key)) return false;

	DeleteBalance(pRoot, key);
	return true;
}