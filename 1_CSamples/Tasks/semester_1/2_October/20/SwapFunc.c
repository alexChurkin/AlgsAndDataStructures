#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
1. Указатели - начало. Обмен значений переменных в отдельной функции
*/
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int n = 2, m = 3;
    swap(&n, &m);
    printf("n = %i, m = %i", n, m);
}