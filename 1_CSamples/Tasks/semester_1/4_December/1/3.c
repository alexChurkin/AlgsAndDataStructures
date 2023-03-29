#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
3. Приближённый косинус по формуле Тейлора (переполнение double при больших x)
*/
double my_cos(double x, int n)
{
    int sign = 1;
    double a = 1;
    double result = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        result += sign * a;
        a *= (x / (2 * i - 1)) * (x / (2 * i));
        sign = -sign;
    }
    return result;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    double x;
    int n;
    printf("В какой точке?\n");
    scanf("%lf", &x);
    printf("Сколько слагаемых?\n");
    scanf("%i", &n);

    double c = cos(x);
    double my_c = my_cos(x, n);

    printf(">Настоящий cos(%lf) = %lf\n", x, c);
    printf(">Приближённый cos(%lf) = %lf\n", x, my_c);
    printf("error(%lf) =  %e", x, abs(c - my_c));
}