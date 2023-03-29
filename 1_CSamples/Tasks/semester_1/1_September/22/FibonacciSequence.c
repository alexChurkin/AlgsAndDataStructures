#include <stdio.h>

/*
3. Последовательность Фибоначчи
*/
void main()
{
    int i, n, a0 = 1, a1 = 1, a2;
    scanf("%i", &n);
    printf("Output:\n", a2);
    printf("%i\n", a0);
    printf("%i\n", a1);
    for (i = 1; i < n; i++)
    {
        a2 = a0 + a1;
        a0 = a1;
        a1 = a2;
        printf("%i\n", a2);
    }
}