// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

constexpr int MAX_VECTOR_SIZE = 100000000;
constexpr int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора ......................................
template <class ValType>
class TVector
{
protected:
	ValType* pVector;
	int Size;       // размер вектора
	int StartIndex; // индекс первого элемента вектора

public:
	TVector(int _size = 10, int _startIndex = 0);
	TVector(const TVector& v); // конструктор копирования

	~TVector();

	int GetSize() { return Size; } // размер вектора
	int GetStartIndex() { return StartIndex; } // индекс первого элемента

	ValType& operator[](int pos); // доступ

	bool operator==(const TVector& v) const; // сравнение
	bool operator!=(const TVector& v) const; // сравнение

	TVector& operator=(const TVector& v);    // присваивание

	// скалярные операции
	TVector operator+(const ValType& val);  // прибавить скаляр
	TVector  operator-(const ValType& val); // вычесть скаляр
	TVector  operator*(const ValType& val); // умножить на скаляр

	// векторные операции
	TVector operator+(const TVector& v); // сложение
	TVector operator-(const TVector& v); // вычитание
	ValType operator*(const TVector& v); // скалярное произведение

	// ввод-вывод
	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i] << ' ';
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int _size, int _startIndex)
{
	if (_size <= 0 || _size > MAX_VECTOR_SIZE)
		throw _size;
	if (_startIndex < 0 || _startIndex > MAX_VECTOR_SIZE)
		throw _startIndex;

	Size = _size;
	StartIndex = _startIndex;
	pVector = new ValType[Size];
}

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType>& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[v.Size];

	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
}

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos < 0 || pos >= StartIndex + Size) throw pos;

	return pVector[pos - StartIndex];
}

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector& v) const
{
	if (v.Size != Size) return false;

	for (int i = 0; i < Size; i++)
		if (pVector[i] != v.pVector[i])
			return false;
	return true;
}

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector& v) const
{
	if (v.Size != Size) return true;

	for (int i = 0; i < Size; i++)
		if (pVector[i] != v.pVector[i])
			return true;
	return false;
}

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	if (Size != v.Size) {
		Size = v.Size;
		delete[] pVector;
		pVector = new ValType[v.Size];
	}
	StartIndex = v.StartIndex;

	for (int i = 0; i < Size; i++) {
		pVector[i] = v.pVector[i];
	}
	return *this;
}

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector res(Size);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] + val;
	return res;
}

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector res(Size);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] - val;
	return res;
}

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector res(Size);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] * val;
	return res;
}

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
	if (v.Size != Size) throw Size;

	TVector res(Size);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] + v.pVector[i];
	return res;
}

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
	if (v.Size != Size) throw Size;

	TVector res(Size);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] - v.pVector[i];
	return res;
}

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
	if (Size != v.Size) throw Size;

	ValType res = 0;

	for (int i = 0; i < Size; i++)
		res += (pVector[i] * v.pVector[i]);
	return res;
}


// Верхнетреугольная матрица ...........................
template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
	TMatrix(int _size = 10);
	TMatrix(const TMatrix& tmp);                   // копирование
	TMatrix(const TVector<TVector<ValType> >& tmp);// преобразование типа
	bool operator==(const TMatrix& mt) const;      // сравнение
	bool operator!=(const TMatrix& mt) const;      // сравнение
	TMatrix& operator=(const TMatrix& tmp);        // присваивание
	TMatrix operator+(const TMatrix& tmp);         // сложение
	TMatrix operator-(const TMatrix& tmp);         // вычитание
	TMatrix operator*(const TMatrix& tmp);         // умножение (матриц)
	~TMatrix() { }

	// ввод / вывод
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int _size) : TVector<TVector<ValType>>(_size)
{
	if (_size <= 0 || _size > MAX_MATRIX_SIZE) throw _size;

	for (int i = 0; i < Size; i++)
	{
		TVector<ValType> v(Size - i, i);
		pVector[i] = v;
	}
}

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
	TVector<TVector<ValType>>(mt)
{
}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>>& mt) :
	TVector<TVector<ValType> >(mt)
{
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
	return TVector<TVector<ValType>>::operator==(mt);
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	return TVector<TVector<ValType>>::operator!=(mt);
}

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size) {
		delete[] pVector;
		Size = mt.Size;
		pVector = new TVector<ValType>[Size];
	}

	for (int i = 0; i < Size; i++)
		pVector[i] = mt.pVector[i];

	return *this;
}

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return TVector<TVector<ValType>>::operator+(mt);
}

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	return TVector<TVector<ValType>>::operator-(mt);
}

template <class ValType> // умножение
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& mt) {
	if (Size != mt.Size) {
		throw Size;
	}

	TMatrix result(Size);

	//Заполним элементы result[i][j] новой матрицы (только выше диагонали)
	for (int i = 0; i < Size; i++) {
		for (int j = i; j < Size; j++) {
			//Здесь вычислим значение элемента result[i][j]
			ValType sum = pVector[0][0] * 0;

			//Индекс элементов левой матрицы (i_left - строка - фиксирована)
			int i_left = i, j_left = i;
			//Индексы элементов правой матрицы (j_right - столбец - фиксирован)
			int i_right = i, j_right = j;
			//cout << "element res[" << i << "][" << j << "]" << endl;
			//cout << "initial sum = " << sum << endl;

			//cout << endl;

			while ((j_left <= Size - 1) && (i_right <= j)) {
				//cout << "i_left = " << i_left << ", j_left = " << j_left << endl;
				//cout << "i_right = " << i_right << ", j_right = " << j_right << endl;

				sum += pVector[i_left][j_left] * mt.pVector[i_right][j_right];
				j_left++;
				i_right++;
			}
			//cout << "resulting sum = " << sum << endl;

			//cout << endl;
			//cout << endl;

			result[i][j] = sum;
		}
	}

	return result;
}

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
