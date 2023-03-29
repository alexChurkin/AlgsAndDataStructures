#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>
#include <locale.h>

/*
4. Бинарный поиск индекса элемента a в отсортированном массиве
   (введённом с клавиатуры)
*/
void main()
{
    setlocale(LC_ALL, "");
    int i;
    int a;
    int l, m, r;
    int F = 0;
    int mas[SIZE];

    printf("Введите %i элементов исходного массива (по возрастанию!):\n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        scanf("%i", &mas[i]);
    }

    printf("Введите искомый элемент:\n");
    scanf("%i", &a);
    l = 0;
    r = SIZE - 1;
    while (r >= l)
    {
        m = (r + l) / 2;
        if (a == mas[m])
        {
            F = 1;
            break;
        }
        else if (a > mas[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    if (F == 1)
        printf("Элемент найден на позиции %i", m);
    else
        printf("Элемент не найден");
}