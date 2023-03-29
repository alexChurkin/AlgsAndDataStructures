#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
#include <locale.h>
//Для rand и time
#include <stdlib.h>
#include <time.h>

/*
3.2. Узнать индекс введённого элемента (если его нет, сообщить об этом)
     (ПОИСК С БАРЬЕРОМ)
*/
void main()
{
    setlocale(LC_ALL, "");
    int i, e, pos = -1;
    int mas[SIZE + 1];

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
    mas[SIZE] = e;

    i = 0;
    while (mas[i] != e)
        i++;
    if (i != SIZE)
        printf("Элемент найден на позиции %i", i);
    else
        printf("Элемент не найден");
}