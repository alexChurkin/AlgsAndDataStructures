#include <stdio.h>

/*
5. Нахождение количества слагаемых 1/i, при которых их сумма больше x
*/
void main()
{
    int n = 1;
    float x;
    float sum = 0.0f;
    scanf("%f", &x);
    while (sum < x)
    {
        sum += 1.0f / n;
        //printf("n = %i: sum = %f\n", n, sum);
        n++;
    }
    printf("Слагаемых: %i", n - 1);
}