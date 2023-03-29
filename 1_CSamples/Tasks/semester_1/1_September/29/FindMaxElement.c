#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
#include <locale.h>
//Для rand и time
#include <stdlib.h>
#include <time.h>

/*
2. Найти наибольший элемент в заданном случайным образом массиве от 0 до 100
*/
void main()
{
    setlocale(LC_ALL, "");
    int i, max;
    int mas[SIZE];

    srand((unsigned int)time(NULL));
    printf("Дан массив случайных чисел: [ ");
    for (i = 0; i < SIZE; i++)
    {
        mas[i] = rand() % 100;
        printf("%i ", mas[i]);
    }
    printf("]\n");

    max = mas[0];

    for (i = 1; i < SIZE; i++)
        if (mas[i] > max)
            max = mas[i];
    printf("Вывод: max = %i", max);
}