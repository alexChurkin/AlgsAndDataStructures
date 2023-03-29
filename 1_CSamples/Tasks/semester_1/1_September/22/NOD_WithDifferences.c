#include <stdio.h>

/*
4.1. Поиск НОД 2-х чисел через разности (-)
*/
void main()
{
    int a, b;
    scanf("%i %i", &a, &b);
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    if (a > 0)
        printf("HOD = %i", a);
    else
        printf("HOD = %i", b);
}