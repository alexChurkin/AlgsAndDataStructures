#include <iostream>
#include <locale.h>
#include "gauss_tools.h"
#include "system_solver.h"
using namespace std;

double** A = NULL;
double* x = NULL;
double* b = NULL;

int n;

double** A1 = NULL;
double* b1 = NULL;
double max_err;
bool res;

void print_menu()
{
	cout << "Меню:\n"
		<< "-----------------\n"
		<< "1. Задать новую систему\n"
		<< "2. Записать систему в файл\n"
		<< "3. Считать систему из файла\n"
		<< "4. Выход из программы\n"
		<< "-----------------\n";
}

void gaussificate()
{
	A1 = copy_matrix(A, n);
	b1 = copy_vector(b, n);
	res = gauss_solve(A, x, b, n);
	if (res)
	{
		print_solution(x, n);
		max_err = error_check(A1, x, b1, n);
		cout << scientific;
		cout << "Погрешность = " << max_err << "\n";
		cout << fixed;
	}
	cout << "Что дальше?..\n";
}

int main()
{
	setlocale(LC_ALL, "russian");
	print_menu();

	short inp;
	while (true)
	{
		cin >> inp;
		switch (inp) {
		case 1:
			destroy_system(A, A1, x, b, b1, n);
			request_system(A, b, n);
			gaussificate();
			break;
		case 2:
			save_to_file(A1, b1, n);
			break;
		case 3:
			destroy_system(A, A1, x, b, b1, n);
			load_from_file(A, b, n);
			gaussificate();
			break;
		case 4:
			cout << "Программа завершена.";
			return 0;
		}
	}
}