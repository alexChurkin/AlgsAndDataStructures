#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 5

/*
3. Задан массив размера SIZE (с клавиатуры).
   Определить количество перемен знака в массиве
   (элементы могут быть отрицательны и положительны)
*/
void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[SIZE];
    int i = 0, k = 0;

    //Заполнение массива с клавиатуры
    while (i < SIZE)
        scanf("%i", &arr[i++]);
    //Подсчёт количества перемен знака
    for (i = 1; i < SIZE; i++)
    {
        if (arr[i - 1] < 0 && arr[i] > 0 || arr[i - 1] > 0 && arr[i] < 0)
            k++;
    }
    printf("Обнаружено перемен знака: %i", k);
}