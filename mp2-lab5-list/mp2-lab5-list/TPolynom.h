#pragma once
#include<cmath>
#include<sstream>
#include "THeadList.h"
using namespace std;

/* ..................... TMonom ..................... */

struct TMonom
{
	//�����������
	double coeff;

	//������� ��� x, y � z
	int x, y, z;

	TMonom();
	TMonom(double _coeff, int _x, int _y, int _z);
	TMonom(int _x, int _y, int _z);

	//��������� � ��������� �� ����������� ���������
	bool operator==(const TMonom& other) const;
	bool operator!=(const TMonom& other) const;
	bool operator<(const TMonom& other) const;
	bool operator>(const TMonom& other) const;

	//IsConst() <-> ������� ��� x, y � z ����� 0
	bool IsConst() const;

	TMonom operator*(const TMonom& other);

	//������� ������� ����� ��� ������������ � �����
	friend std::ostream& operator<<(std::ostream& os, TMonom& monom)
	{
		if (monom.x != 0)
		{
			os << "x";
			if (monom.x != 1)
				os << monom.x;
		}
		if (monom.y != 0)
		{
			os << "y";
			if (monom.y != 1)
				os << monom.y;
		}
		if (monom.z != 0)
		{
			os << "z";
			if (monom.z != 1)
				os << monom.z;
		}
		return os;
	}
};

TMonom::TMonom()
{
	coeff = 0;
	x = y = z = 0;
}

TMonom::TMonom(
	double _coeff, int _x, int _y, int _z)
{
	coeff = _coeff;
	x = _x;
	y = _y;
	z = _z;
}

TMonom::TMonom(int _x, int _y, int _z)
{
	coeff = 0;
	x = _x;
	y = _y;
	z = _z;
}

bool TMonom::operator==(const TMonom& other) const
{
	return (x == other.x && y == other.y && z == other.z);
}

bool TMonom::operator!=(const TMonom& other) const
{
	return (x != other.x || y != other.y || z != other.z);
}

bool TMonom::operator<(const TMonom& other) const
{
	if (x < other.x) return true;
	else if (x == other.x)
	{
		if (y < other.y) return true;
		else if (y == other.y)
		{
			return z < other.z;
		}
		else return false;
	}
	else return false;
}

bool TMonom::operator>(const TMonom& other) const
{
	return !operator<(other) && !operator==(other);
}

bool TMonom::IsConst() const
{
	return x == 0 && y == 0 && z == 0;
}

TMonom TMonom::operator*(const TMonom& other)
{
	TMonom result;
	result.coeff = coeff * other.coeff;
	result.x = x + other.x;
	result.y = y + other.y;
	result.z = z + other.z;
	return result;
}

/* .................... TPolynom .................... */

class TPolynom : public THeadList<TMonom>
{
protected:
	void Print(std::ostream& os) const;

public:
	TPolynom();

	//const TPolynom& �� �����, ����� Reset � GetNext
	//�� ����� ��������
	TPolynom(TPolynom& other);
	TPolynom(const std::string& polyStr);
	TPolynom& operator=(TPolynom& other);

	void AddMonom(TMonom m);
	void AddMonom(double coeff, int x, int y, int z);

	bool operator==(const TPolynom& other) const;
	bool operator!=(const TPolynom& other) const;

	TPolynom operator+(TPolynom& other);
	TPolynom operator-(TPolynom& other);
	TPolynom operator*(TPolynom& other);
	TPolynom operator*(TMonom& monom);
	TPolynom operator*(double a);

	friend std::ostream& operator<<(
		std::ostream& os,
		TPolynom& p)
	{
		p.Print(os);
		return os;
	}

	friend TPolynom operator*(
		TMonom& m,
		TPolynom& p)
	{
		return p * m;
	}

	friend TPolynom operator*(
		double a,
		TPolynom& p)
	{
		return p * a;
	}
};

void TPolynom::Print(std::ostream& os) const
{
	TNode<TMonom>* _pCurr = pFirst;

	//������� �������
	if (_pCurr == pStop)
	{
		os << "0";
		return;
	}

	//����� ��� ������� ������ ��������
	TMonom m = _pCurr->value;
	double absCoeff = fabs(m.coeff);

	if (m.coeff < 0) os << "- ";

	//����� ��� �����������
	if (m.IsConst())
	{
		os << absCoeff;
	}
	//�� �����������
	else
	{
		if (absCoeff != 1) os << absCoeff << "*";
		os << m;
	}

	_pCurr = _pCurr->pNext;

	for (; _pCurr != pStop; _pCurr = _pCurr->pNext)
	{
		TMonom m = _pCurr->value;
		double absCoeff = fabs(m.coeff);

		if (m.coeff < 0) os << " - ";
		else os << " + ";

		if (m.IsConst())
		{
			os << absCoeff;
		}
		else
		{
			if (absCoeff != 1)
				os << absCoeff << "*";
			os << m;
		}
	}
}

TPolynom::TPolynom() :THeadList::THeadList()
{
	TMonom m;
	m.coeff = 0;
	m.x = m.y = 0, m.z = -1;

	pHead->value = m;
}

TPolynom::TPolynom(TPolynom& other)
{
	TMonom m(0, 0, -1);
	pHead->value = m;
	for (other.Reset(); !other.IsEnd(); other.GoNext())
		InsLast(other.GetCurr());
}

TPolynom::TPolynom(
	const std::string& polyStr): TPolynom()
{
	if (polyStr.length() == 0) return;

	//��������� ����������� ���� ������������
	char lastsgn = '+';

	//��������� ����� ��� ������ ������
	TMonom tm(1, 0, 0, 0);

	int i = 0;
	for (; i < polyStr.size(); i++)
	{
		if (isdigit(polyStr[i]))
		{
			size_t idx;
			double digit = stod(&polyStr[i], &idx);
			ostringstream ss;
			ss << digit;

			tm.coeff = digit;
			i += idx - 1;
		}
		else if (polyStr[i] == 'x' || polyStr[i] == 'X')
		{
			//��� ����� ������ (������� 1)
			if (i + 1 == polyStr.size())
			{
				tm.x += 1;
			}
			//����� ����� ����� ������� (�� 1)
			else if (isdigit(polyStr[i + 1]))
			{
				size_t idx;
				double digit = stod(&polyStr[i + 1], &idx);
				ostringstream ss;
				ss << digit;

				tm.x += digit;
				i += idx;
			}
			//����� ����� ������� 1
			else
			{
				tm.x += 1;
			}
		}
		else if (polyStr[i] == 'y' || polyStr[i] == 'Y')
		{
			//��� ����� ������ (������� 1)
			if (i + 1 == polyStr.size())
			{
				tm.y += 1;
			}
			//����� ����� ����� ������� (�� 1)
			else if (isdigit(polyStr[i + 1]))
			{
				size_t idx;
				double digit = stod(&polyStr[i + 1], &idx);
				ostringstream ss;
				ss << digit;

				tm.y += digit;
				i += idx;
			}
			//����� ����� ������� 1
			else
			{
				tm.y += 1;
			}
		}
		else if (polyStr[i] == 'z' || polyStr[i] == 'Z')
		{
			//��� ����� ������ (������� 1)
			if (i + 1 == polyStr.size())
			{
				tm.z += 1;
			}
			//����� ����� ����� ������� (�� 1)
			else if (isdigit(polyStr[i + 1]))
			{
				size_t idx;
				double digit = stod(&polyStr[i + 1], &idx);
				ostringstream ss;
				ss << digit;

				tm.z += digit;
				i += idx;
			}
			//����� ����� ������� 1
			else
			{
				tm.z += 1;
			}
		}
		//������� � ���������� ���������� ������
		else if (polyStr[i] == '+' || polyStr[i] == '-')
		{
			if (lastsgn == '-') tm.coeff *= (-1);
			AddMonom(tm);
			tm.coeff = 1;
			tm.x = tm.y = tm.z = 0;
			lastsgn = polyStr[i];
		}
	}
	//�������� ���������� ������
	if (lastsgn == '-') tm.coeff *= (-1);
	AddMonom(tm);
}

TPolynom& TPolynom::operator=(TPolynom& other)
{
	//������� ��� ������ (����� pHead)
	while (pFirst != pStop)
	{
		TNode<TMonom>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	//������ ��� �������� ���������� ������� �� pHead
	pFirst = pLast = pPrev = pCurr = pStop = pHead;
	length = 0;

	//�������� ������� �������� �� other
	other.Reset();
	while (!other.IsEnd())
	{
		InsLast(other.GetCurr());
		other.GoNext();
	}
	return *this;
}

void TPolynom::AddMonom(TMonom m)
{
	if (m.coeff == 0) return;

	Reset();
	//������� � ���������� ������, ���� ������� m ������ ��������
	while (m < pCurr->value)
	{
		GoNext();
	}
	//��������� �����������
	//1. ������ ����� � ��������� �� ����-��
	if (pCurr->value == m)
	{
		pCurr->value.coeff += m.coeff;
		//1.1. ����� �������� ���� ������� ����-� 0 - ������� ������� �����
		if (pCurr->value.coeff == 0)
		{
			DelCurr();
		}
	}
	//2. ������ �� ����� - ������� ������� � ��� ������
	else
	{
		InsCurr(m);
	}
}

void TPolynom::AddMonom(double coeff, int x, int y, int z)
{
	AddMonom(TMonom(coeff, x, y, z));
}

bool TPolynom::operator==(const TPolynom& other) const
{
	return ToStr() == other.ToStr();
}

bool TPolynom::operator!=(const TPolynom& other) const
{
	return ToStr() != other.ToStr();
}

TPolynom TPolynom::operator+(TPolynom& other)
{
	TPolynom result(other);
	Reset(); result.Reset();

	while (!IsEnd())
	{
		if (result.pCurr->value > pCurr->value)
		{
			result.GoNext();
		}
		else if (result.pCurr->value < pCurr->value)
		{
			result.InsCurr(pCurr->value);
			GoNext();
		}
		else
		{
			result.pCurr->value.coeff += pCurr->value.coeff;
			if (result.pCurr->value.coeff == 0)
			{
				result.DelCurr();
				GoNext();
			}
			else
			{
				result.GoNext();
				GoNext();
			}
		}
	}
	return result;
}

TPolynom TPolynom::operator-(TPolynom& other)
{
	return operator+(other.operator*(-1));
}

TPolynom TPolynom::operator*(TPolynom& other)
{
	TPolynom result;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		TPolynom temp = m * other;
		result = result + temp;
	}

	return result;
}

TPolynom TPolynom::operator*(TMonom& monom)
{
	TPolynom result;

	if (monom.coeff == 0) return result;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		result.InsLast(m * monom);
	}

	return result;
}

TPolynom TPolynom::operator*(double a)
{
	TPolynom result;

	if (a == 0) return result;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		m.coeff *= a;

		result.InsLast(m);
	}
	return result;
}

/*
//����� ����������� ������ operator+
TPolynom TPolynom::operator+(TPolynom& other)
{
	TPolynom result(other);

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		result.AddMonom(m);
	}
	return result;
}
*/