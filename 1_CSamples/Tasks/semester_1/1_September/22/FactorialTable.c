#include <stdio.h>

/*
2. Таблица факториалов
*/
void main()
{
    int i;
    int n;
    int f = 1;
    scanf("%i", &n);
    printf("Output:\n");
    for (i = 1; i <= n; i++)
    {
        f *= i;
        printf("%i! = %i\n", i, f);
    }
}