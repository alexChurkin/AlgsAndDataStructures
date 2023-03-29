#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input_struct.h"
#include "functions.h"
#include "tableprinter.h"

void print_menu();
void fill_input(input *inp);

void main()
{
	setlocale(LC_CTYPE, "rus");
	int number;
	input inp = { 0.0, 0.0, 0.0, 0, NULL, NULL, "" };

	print_menu();
	fill_input(&inp);
	while (1)
	{
		scanf("%i", &number);
		switch (number)
		{
		case 0:
			printf("\nЗавершение программы.");
			return;
		case 1:
			fill_input(&inp);
			break;
		case 2:
			inp.func = exp; inp.myfunc = my_exp;
			inp.f_name = "exp"; print_table(inp);
			break;
		case 3:
			inp.func = sin; inp.myfunc = my_sin;
			inp.f_name = "sin"; print_table(inp);
			break;
		case 4:
			inp.func = cos; inp.myfunc = my_cos;
			inp.f_name = "cos"; print_table(inp);
			break;
		case 5:
			inp.func = log; inp.myfunc = my_log;
			inp.f_name = "log"; print_table(inp);
			break;
		case 6:
			inp.func = exp; inp.myfunc = my_improved_exp;
			inp.f_name = "*exp"; print_table(inp);
			break;
		case 7:
			inp.func = sin; inp.myfunc = my_improved_sin;
			inp.f_name = "*sin"; print_table(inp);
			break;
		case 8:
			inp.func = cos; inp.myfunc = my_improved_cos;
			inp.f_name = "*cos"; print_table(inp);
			break;
		case 9:
			inp.func = log; inp.myfunc = my_universal_log;
			inp.f_name = "*log"; print_table(inp);
			break;
		case 10:
			print_menu();
			break;
		}
	}
}

void print_menu()
{
	printf("Меню:\n");
	printf("-----------------------------\n");
	printf("> 1 - Обновить входные данные\n");
	printf("--------------------\n");
	printf("> 2 - exp(x)\n> 3 - sin(x)\n");
	printf("> 4 - cos(x)\n> 5 - log(x)\n");
	printf("> 6 - Улучшенный exp(x)\n> 7 - Улучшенный sin(x)\n");
	printf("> 8 - Улучшенный cos(x)\n> 9 - Универсальный log(x)\n");
	printf("--------------------\n");
	printf("> 10 - Показать меню\n");
	printf("> 0 - Выход\n");
}

void fill_input(input *inp)
{
	printf("\nВведите a (начало отрезка), b (конец отрезка),");
	printf(" step (шаг), n (кол-во слагаемых):\n");
	scanf("%lf %lf %lf %d", &(*inp).a, &(*inp).b, 
		&(*inp).step, &(*inp).n);
}