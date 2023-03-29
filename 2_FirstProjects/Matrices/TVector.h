#pragma once
#include <iostream>
#include "Exception.h"
using namespace std;

template <class T>
class TVector
{
private:
	int n;
	T* arr;

public:
	TVector(int _n = 3);
	TVector(const TVector& v);
	~TVector();

	int getSize() const;
	void resize(int _n);

	TVector operator+(const TVector& b) const;
	TVector operator-(const TVector& b) const;
	T operator*(const TVector& b) const;

	TVector operator+(const T& b) const;
	TVector operator-(const T& b) const;
	TVector operator*(const T& b) const;
	TVector operator/(const T& b) const;

	TVector& operator=(const TVector& v);
	TVector& operator+=(const TVector& b);
	TVector& operator-=(const TVector& b);

	TVector& operator+=(const T& b);
	TVector& operator-=(const T& b);
	TVector& operator*=(const T& b);
	TVector& operator/=(const T& b);

	T& operator[](int i);

	friend TVector operator+(const T& a, const TVector<T>& b)
	{
		TVector<T> result(b);
		for (int i = 0; i < result.n; i++)
		{
			result.arr[i] += a;
		}
		return result;
	}

	friend TVector operator-(const T& a, const TVector<T>& b)
	{
		TVector<T> result(b);
		for (int i = 0; i < result.n; i++)
		{
			result.arr[i] = a - result.arr[i];
		}
		return result;
	}

	friend TVector operator*(const T& a, const TVector<T>& b)
	{
		TVector<T> result(b);
		for (int i = 0; i < result.n; i++)
		{
			result.arr[i] *= a;
		}
		return result;
	}

	friend ostream& operator<<(ostream& os, const TVector<T>& v)
	{
		os << '(';
		for (int i = 0; i < v.n - 1; i++)
		{
			os << v.arr[i] << ", ";
		}
		os << v.arr[v.n - 1] << ')';
		return os;
	}

	friend istream& operator>>(istream& is, TVector<T>& v)
	{
		for (int i = 0; i < v.n; i++)
		{
			is >> v.arr[i];
		}
		return is;
	}
};

template <class T>
TVector<T>::TVector(int _n)
{
	if (_n <= 0)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vector size cannot be <= 0");

	n = _n;
	arr = new T[n];

	for (int i = 0; i < n; i++)
		arr[i] = NULL;
}

template <class T>
TVector<T>::TVector(const TVector<T>& v)
{
	n = v.n;
	arr = new T[v.n];
	for (int i = 0; i < n; i++)
		arr[i] = v.arr[i];
}

template <class T>
TVector<T>::~TVector()
{
	delete[] arr;
}

template <class T>
int TVector<T>::getSize() const
{
	return n;
}

template <class T>
void TVector<T>::resize(int _n)
{
	if (_n == n)
		return;

	T* arr_new = new T[_n];
	for (int i = 0; i < _n; i++)
		arr_new[i] = NULL;

	//Новый размер больше старого (просто копируем значения)
	if (_n > n)
		for (int i = 0; i < n; i++)
			arr_new[i] = arr[i];
	//Новый меньше старого (копируем значения, которые уберутся)
	else
		for (int i = 0; i < _n; i++)
			arr_new[i] = arr[i];

	delete[] arr;
	arr = arr_new;
	n = _n;
}

template <class T>
TVector<T> TVector<T>::operator+(const TVector<T>& b) const
{
	if (n != b.n)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vectors have different dimensions");

	TVector<T> result(n);
	for (int i = 0; i < n; i++)
		result[i] = arr[i] + b.arr[i];
	return result;
}

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T>& b) const
{
	if (n != b.n)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vectors have different dimensions");

	TVector<T> result(n);
	for (int i = 0; i < n; i++)
		result[i] = arr[i] - b.arr[i];
	return result;
}

template <class T>
T TVector<T>::operator*(const TVector<T>& b) const
{
	if (n != b.n)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vectors have different dimensions");

	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i] * b.arr[i];
	return sum;
}

template <class T>
TVector<T> TVector<T>::operator+(const T& b) const
{
	TVector<T> result(n);
	for (int i = 0; i < n; i++)
		result[i] = arr[i] + b;
	return result;
}

template <class T>
TVector<T> TVector<T>::operator-(const T& b) const
{
	TVector<T> result(n);
	for (int i = 0; i < n; i++)
		result[i] = arr[i] - b;
	return result;
}

template <class T>
TVector<T> TVector<T>::operator*(const T& b) const
{
	TVector<T> result(n);
	for (int i = 0; i < n; i++)
		result[i] = arr[i] * b;
	return result;
}

template <class T>
TVector<T> TVector<T>::operator/(const T& b) const
{
	if (b == NULL)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Division by zero");

	TVector<T> result(n);
	for (int i = 0; i < n; i++)
		result[i] = arr[i] / b;
	return result;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& v)
{
	if (this == &v)
		return *this;

	if (n != v.n)
	{
		n = v.n;
		delete[] arr;
		arr = new T[n];
	}

	for (int i = 0; i < n; i++)
		arr[i] = v.arr[i];

	return *this;
}

template <class T>
TVector<T>& TVector<T>::operator+=(const TVector<T>& b)
{
	if (n != b.n)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vectors have different dimensions");

	for (int i = 0; i < n; i++)
		arr[i] += b.arr[i];

	return *this;
}

template <class T>
TVector<T>& TVector<T>::operator-=(const TVector<T>& b)
{
	if (n != b.n)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vectors have different dimensions");

	for (int i = 0; i < n; i++)
		arr[i] -= b.arr[i];

	return *this;
}

template <class T>
TVector<T>& TVector<T>::operator+=(const T& b)
{
	for (int i = 0; i < n; i++)
		arr[i] += b;

	return *this;
}

template <class T>
TVector<T>& TVector<T>::operator-=(const T& b)
{
	for (int i = 0; i < n; i++)
		arr[i] -= b;

	return *this;
}

template <class T>
TVector<T>& TVector<T>::operator*=(const T& b)
{
	for (int i = 0; i < n; i++)
		arr[i] *= b;

	return *this;
}

template <class T>
TVector<T>& TVector<T>::operator/=(const T& b)
{
	if (b == NULL)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Division by zero");

	for (int i = 0; i < n; i++)
		arr[i] /= b;

	return *this;
}

template <class T>
T& TVector<T>::operator[](int i)
{
	if (i >= 0 && i < n)
		return arr[i];
	else
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Index out of bounds");
}