// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	TMatrix<int> a(5), b(5), c(5);

	cout << "������������ �������� ��������� ������������� ����������� ������"
		<< endl;
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}
	c = a;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a" << endl << c << endl;
	return 0;
}