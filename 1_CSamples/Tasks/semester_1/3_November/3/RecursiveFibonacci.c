#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
2. Рекурсивное вычисление n-го числа Фибоначчи
*/

int countFibonacci(int count)
{
    if (count == 1 || count == 2)
        return 1;
    return countFibonacci(count - 2) + countFibonacci(count - 1);
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    printf("Введите номер требуемого числа Фибоначчи: ");
    scanf("%i", &n);
    printf("Number: %i", countFibonacci(n));
}