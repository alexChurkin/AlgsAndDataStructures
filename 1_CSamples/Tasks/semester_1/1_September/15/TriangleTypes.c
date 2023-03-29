#include <stdio.h>
#include <math.h>

/* 4. Определение типа треугольника по заданным сторонам a, b, c */
void main()
{
    float a, b, c;
    float temp;
    scanf_s("%f %f %f", &a, &b, &c);

    if (a == 0 || b == 0 || c == 0)
    {
        printf("01 - Такого треугольника не существует");
    }
    else if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("02 - Такого треугольника не существует");
    }
    else if (a == b || a == c || b == c)
    {
        if (a == b && b == c)
            printf("2 - Равносторонний");
        else
            printf("3 - Равнобедренный");
    }
    else
    {
        //Делаем "c" наибольшим коэфициентом
        if (b < a)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (c < b)
        {
            temp = b;
            b = c;
            c = temp;
        }
        temp = a * a + b * b;
        if (c * c == temp)
            printf("4 - Прямоугольный");
        else if (c * c < temp)
            printf("5 - Остроугольный");
        else
            printf("6 - Тупоугольный");
    }
}