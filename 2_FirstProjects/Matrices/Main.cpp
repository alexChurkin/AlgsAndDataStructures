#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
#include "TMatrix.h"
using namespace std;

void test_vector()
{
	cout << "\\.........................Тесты векторов"
		"........................./\n\n";
	//v1 = (1, 2, 3)
	//v2 = (5, 5, 5)
	TVector<double> v1(3);
	TVector<double> v2(3);

	//cout << "Введите 2 вектора длины 3:\n";
	//cin >> v1 >> v2;
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	v2[0] = v2[1] = v2[2] = 5;

	cout << "Дано:\n";
	cout << "========================\n";
	cout << "v1 = " << v1 << "\n";
	cout << "v2 = " << v2 << "\n";
	cout << "========================\n\n";

	//////////////////////////////////////
	TVector<double> test1 = v1 + v2;
	cout << "v1 + v2 = " << test1 << '\n';

	TVector<double> test2 = v1 - v2;
	cout << "v1 - v2 = " << test2 << '\n';

	double test3 = v1 * v2;
	cout << "v1 * v2 = " << test3 << '\n';
	//////////////////////////////////////
	TVector<double> test4 = v1 + 1;
	cout << "v1 + 1 = " << v1 + 1 << '\n';

	TVector<double> test5 = v1 - 1;
	cout << "v1 - 1 = " << v1 - 1 << '\n';

	TVector<double> test6 = v1 * 2;
	cout << "v1 * 2 = " << v1 * 2 << '\n';

	TVector<double> test7 = v1 / 2;
	cout << "v1 / 2 = " << v1 / 2 << '\n';
	//////////////////////////////////////
	TVector<double> test8 = v1;
	cout << "test8  = v1          || = " << test8 << '\n';

	TVector<double> test9 = (v1 += v2);
	cout << "test9  = (v1 += v2)  || = " << test9 << '\n';

	TVector<double> test10 = (v1 -= v2);
	cout << "test10 = (v1 -= v2)  || = " << test10 << '\n';
	//////////////////////////////////////
	TVector<double> test11 = (v1 += 2);
	cout << "test11 = (v1 += 2)   || = " << test11 << '\n';

	TVector<double> test12 = (v1 -= 2);
	cout << "test12 = (v1 -= 2)   || = " << test12 << '\n';

	TVector<double> test13 = (v1 *= 2);
	cout << "test13 = (v1 *= 2)   || = " << test13 << '\n';

	TVector<double> test14 = (v1 /= 2);
	cout << "test14 = (v1 /= 2)   || = " << test14 << '\n';

	TVector<double> test15 = 1.0 + v1;
	cout << "1 + v1 = " << test15 << '\n';

	TVector<double> test16 = 1.0 - v1;
	cout << "1 - v1 = " << test16 << '\n';

	TVector<double> test17 = 2.0 * v1;
	cout << "2 * v1 = " << test17 << "\n\n";

	TVector<double> test18(5);
	test18[0] = 10;
	test18[1] = 20;
	test18[2] = 30;
	test18[3] = 40;
	test18[4] = 50;
	cout << "Создан вектор            test18 = " << test18 << '\n';
	test18.resize(8);
	cout << "Изменён его размер на 8: test18 = " << test18 << '\n';
	test18.resize(3);
	cout << "Изменён его размер на 3: test18 = " << test18 << "\n\n";

	//........Демонстрация ловли исключений........
	//Некорректное обращение []
	try
	{
		double a = test17[10];
	}
	catch (Exception e)
	{
		cout << "Произошла ошибка:\n" << e << '\n';
	}

	//Некорректная сумма
	TVector<double> t1(3);
	TVector<double> t2(4);
	try
	{
		TVector<double> t3 = t1 + t2;
	}
	catch (Exception e)
	{
		cout << "Произошла ошибка:\n" << e << '\n';
	}

	//Некорректное создание вектора
	try
	{
		TVector<double> t4(-15);
	}
	catch (Exception e)
	{
		cout << "Произошла ошибка:\n" << e << '\n';
	}

	//Некорректное деление вектора (деление на 0)
	try
	{
		TVector<double> t5 = v1 / 0;
	}
	catch (Exception e)
	{
		cout << "Произошла ошибка:\n" << e << '\n';
	}
}

void test_matrix()
{
	cout << "\\.........................Тесты матриц"
		"........................./\n\n";
	TMatrix<double> m(3);
	TMatrix<double> e2(3);

	double k = 1;
	for (int i = 0; i < m.getSize(); i++)
		for (int j = 0; j < m.getSize(); j++)
			m[i][j] = k++;

	e2[0][0] = e2[1][1] = e2[2][2] = 2;
	//cout << "Введите матрицу E:\n";
	//cin >> e;

	TVector<double> v(3);
	v[0] = v[1] = v[2] = 10;

	cout << "Дано:\n";
	cout << "=====================================\n";
	cout << "M =\n" << m << "\n";
	cout << "E2 =\n" << e2 << "\n";
	cout << "V = " << v << "\n";
	cout << "=====================================\n\n";

	cout << "M + E2 =\n" << m + e2 << '\n';
	cout << "M - E2 =\n" << m - e2 << '\n';
	cout << "M * E2 =\n" << m * e2 << '\n';

	cout << "M + 2 =\n" << m + 2 << '\n';
	cout << "M - 2 =\n" << m - 2 << '\n';
	cout << "M * 2 =\n" << m * 2 << '\n';
	cout << "M / 2 =\n" << m / 2 << '\n';


	TMatrix<double> p = m;
	cout << "P = M =\n" << p << '\n';
	cout << "P += E2 =\n" << (p += e2) << '\n';
	cout << "P -= E2 =\n" << (p -= e2) << '\n';
	cout << "P *= E2 =\n" << (p *= e2) << '\n';

	m += 2;
	cout << "M += 2 =\n" << m << '\n';
	m -= 2;
	cout << "M -= 2 =\n" << m << '\n';
	m *= 2;
	cout << "M *= 2 =\n" << m << '\n';
	m /= 2;
	cout << "M /= 2 =\n" << m << '\n';

	cout << "2 + M =\n" << 2 + m << '\n';
	cout << "2 - M =\n" << 2 - m << '\n';
	cout << "2 * M =\n" << 2 * m << '\n';

	cout << "M * V = " << m * v << "\n\n";

	try {
		cout << "TMatrix<double> k(-1):\n";
		TMatrix<double> k(-1);
	}
	catch (Exception e) {
		cout << e << '\n';
	}

	try {
		TMatrix<double> k(2);
		cout << "K(2) * M(3):\n";
		k* m;
	}
	catch (Exception e) {
		cout << e << '\n';
	}

	try {
		cout << "M / 0:\n";
		TMatrix<double> m0 = m / 0;
	}
	catch (Exception e) {
		cout << e << '\n';
	}

	try {
		cout << "K * V (размерность матрицы K - 2, вектора V - 3):\n";
		TMatrix<double> k(2);
		k[0][0] = k[1][1] = 5;
		TVector<double> kv = k * v;
	}
	catch (Exception e) {
		cout << e << '\n';
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	test_vector();
	cout << '\n';
	test_matrix();
	return 0;
}