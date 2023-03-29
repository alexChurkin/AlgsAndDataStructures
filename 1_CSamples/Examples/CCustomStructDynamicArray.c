#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
Пример динамического выделения памяти под массив custom struct
*/

typedef struct row {
	double x;
	double fx;
	double my_fx;
	double error;
} row;

void main()
{
    setlocale(LC_CTYPE, "rus");
    //Выделим память
    row *rows = (row*) malloc(sizeof(row) * 100);

    for (int i = 0; i < 100; i++) {
        row r = { i, i + 1, i + 2, i + 3 };
        rows[i] = r;
	}

    for (int i = 0; i < 100; i++) {
        printf("%lf %lf %lf %lf\n", rows[i].x, 
                rows[i].fx, rows[i].my_fx, rows[i].error);
	}
    free(rows);
}