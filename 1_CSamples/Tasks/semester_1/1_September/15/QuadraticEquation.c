#include <stdio.h>
#include <math.h>

/* 2. Решение квадратных уравнений */
void main()
{
    float a, b, c, D, x1, x2;
    float x, y;

    scanf_s("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c != 0)
                printf("No roots");
            else
                printf("Any x");
            return;
        }
        printf("Linear equation, one root: x = %f", -c / b);
        return;
    }

    D = b * b - 4 * a * c;

    if (D < 0)
    {
        printf("No rational roots (D = %f)", D);
        D = -D;
        //Действительная часть результата
        x = -b / (2 * a);
        //Комплексная часть результата
        y = sqrt(D) / (2 * a);
        printf("\nComplex roots:\n %f +- %f", x, y);
    }
    else
    {
        if (D == 0)
        {
            x1 = -b / (2 * a);
            printf("One root: x = %f", x1);
        }
        else
        {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            printf("Two roots: x1 = %f, x2 = %f", x1, x2);
        }
    }
}