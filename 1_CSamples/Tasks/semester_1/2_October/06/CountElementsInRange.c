#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#define SIZE 10

/*
1. Задан массив размера SIZE (с клавиатуры).
   Подсчитать число эл-тов массива, надодящихся в заданном диапазоне [c-d; c+d]
*/
void main()
{
    setlocale(LC_CTYPE, "rus");
    int i = 0, c, d, k = 0;
    int arr[SIZE];

    scanf("%i %i", &c, &d);

    //Заполнение массива с клавиатуры
    while (i < SIZE)
        scanf("%i", &arr[i++]);
    //Проверка каждого элемента
    for (i = 0; i < SIZE; i++)
    {
        if (abs(arr[i] - c) <= d)
            k++;
    }
    printf("Элементов, находящихся в заданном диапазоне: %i", k);
}