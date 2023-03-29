#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

/*
1. Оформить вычисление факториала как функцию
*/
int factorial(int n)
{
    int fact = 1;
    int i;
    for (i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int n, res;
    scanf("%i", &n);
    res = factorial(n);
    printf("Factorial = %i", res);
}