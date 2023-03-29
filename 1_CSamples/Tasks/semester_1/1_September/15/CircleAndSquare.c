#include <stdio.h>
#include <math.h>

/* 1. Взаимное расположение круга и квадрата */
void main()
{
    float a, r;
    float d;
    scanf("%f %f", &a, &r);
    d = sqrt(2 * a * a);

    if (a / 2 > r)
        printf("1 Круг полностью внутри квадрата (нет пересечений)");
    else
    {
        if (a / 2 == r)
            printf("2 Круг вписан в квадрат");
        else
            if (r > a / 2 && r < d)
                printf("3 Круг пересекается с квадратом");
            else
                printf("4 Квадрат внутри круга");
    }
}