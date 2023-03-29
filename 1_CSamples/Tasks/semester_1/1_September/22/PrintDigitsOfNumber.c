#include <stdio.h>

/*
7. Вывод на экран цифр заданного числа
*/
void main()
{
    int n, res;
    scanf("%i", &n);

    res = n % 10;
    while (n > 0)
    {
        printf("%i\n", res);
        n /= 10;
        res = n % 10;
    }
}