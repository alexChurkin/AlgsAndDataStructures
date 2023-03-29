#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
1. Экспонента по формуле Тейлора (правильная и неправильная)
*/

int my_factorial(int n)
{
    int fact = 1;
    int i;
    for (i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

double my_pow(double x, int m)
{
    double result = 1;
    for (int i = 1; i <= m; i++)
        result *= x;
    return result;
}

//Неправильная экспонента
//т.к. при вычислении больших факториалов возникает переполнение
//и уход в бесконечность
double my_exp_wrong(double x, int n)
{
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result += (my_pow(x, i) / my_factorial(i));
    }
    return result;
}

//Правильная экспонента
//Например:
//f(x) = f(0) + f'(0)/1! * x + f''(0)/2! * x^2 + + f'''(0)/3! * x^3 + ...
double my_exp(double x, int n)
{
    double result = 1;
    double a = 1;
    for (int i = 1; i <= n; i++)
    {
        a *= (x / i);
        result += a;
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
    scanf("%lf", &n);

    double y = exp(x);
    double my_y_wrong = my_exp_wrong(x, n);
    double my_y = my_exp(x, n);

    printf("exp(%lf) = %lf\n", x, y);
    printf("My non-optimal exp(%lf) = %lf\n", x, my_y_wrong);
    printf("My optimal exp(%lf) = %lf\n", x, my_y);
    printf("error(%lf) =  %e", x, y - my_y);
}