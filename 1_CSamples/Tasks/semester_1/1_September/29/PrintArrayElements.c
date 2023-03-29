#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
#include <locale.h>

/*
1. Задан массив размера SIZE (во всех след. задачах тоже). Вывести на экран эл-ты,
   введённые с клавиатуры
*/
void main()
{
    setlocale(LC_ALL, "");
    int sum = 0, i;
    int arr[SIZE];

    for (i = 0; i < SIZE; i++)
        scanf("%i", &arr[i]);
    for (i = 0; i < SIZE; i++)
        sum += arr[i];
    printf("sum = %i", sum);
}