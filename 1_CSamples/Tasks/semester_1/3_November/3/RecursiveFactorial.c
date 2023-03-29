#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
1. Рекурсии: начало. Факториал
*/

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    printf("Введите n: ");
    scanf("%i", &n);
    printf("Factorial = %i", factorial(n));
}