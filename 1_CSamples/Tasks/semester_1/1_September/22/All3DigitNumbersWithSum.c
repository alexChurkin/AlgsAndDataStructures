#include <stdio.h>

/*
6. Ввод: целое число [0;27];
   Вывод: все 3-хзначные числа, сумма цифр которых совпадает с введённым числом
*/
void main()
{
    int n;
    int c1, c2, c3;
    int i;

    scanf("%i", &n);
    printf("Output:\n", i);

    for (i = 0; i <= 999; i++)
    {
        c3 = i % 10;
        c2 = (i / 10) % 10;
        c1 = (i / 100);
        if (c1 + c2 + c3 == n)
            printf("%i\n", i);
    }
}