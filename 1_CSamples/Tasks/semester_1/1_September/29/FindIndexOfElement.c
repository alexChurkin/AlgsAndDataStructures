#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
#include <locale.h>
//Для rand и time
#include <stdlib.h>
#include <time.h>

/*
3.1. Узнать индекс введённого элемента (если его нет, сообщить об этом)
*/
void main()
{
    setlocale(LC_ALL, "");
    int i, e, pos = -1;
    int mas[SIZE];

    srand((unsigned int)time(NULL));
    printf("Дан массив случайных чисел: [ ");
    for (i = 0; i < SIZE; i++)
    {
        mas[i] = rand() % 100;
        printf("%i ", mas[i]);
    }
    printf("]\n");

    printf("Введите элемент, который нужно найти:\n");
    scanf("%i", &e);

    for (i = 0; i < SIZE; i++)
    {
        if (mas[i] == e)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        printf("Элемент не найден");
    else
        printf("Элемент найден на позиции %i", pos);
}