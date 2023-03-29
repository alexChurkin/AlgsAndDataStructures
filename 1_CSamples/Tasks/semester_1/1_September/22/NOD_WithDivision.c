#include <stdio.h>

/*
4.2. Поиск НОД 2-х чисел через целочисленное деление остатки (/, %)
*/
void main()
{
    int a, b;
    //Остаток от деления
    int res = -1;

    scanf("%i %i", &a, &b);

    if (a > 0 && b == 0)
    {
        printf("HOD = %i", a);
        return;
    }
    else if (b > 0 && a == 0)
    {
        printf("HOD = %i", b);
        return;
    }

    while (res != 0)
    {
        res = a % b;
        a = b;
        b = res;
    }
    printf("HOD = %i", a);
}