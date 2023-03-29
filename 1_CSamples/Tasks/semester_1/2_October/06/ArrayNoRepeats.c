#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 5

/* 
4. Задан массив arr размера SIZE. Сформировать на его основе массив res без повторений.
*/

/*
Функция, возвращающая: 
1, если элемент уже содержится внутри нового массива,
0, если нет
Проверка производится до заданного limit (правая граница), не включая сам limit
*/
int contains(int arrRes[], int element, int limit)
{
    int k;
    for (k = 0; k < limit; k++)
    {
        if (arrRes[k] == element)
            return 1;
    }
    return 0;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[SIZE];
    int res[SIZE];
    //i - счётчик для arr, j - счётчик количества элементов в конечном массиве arrRes
    int i, j = 0;

    printf("Введите %i элементов массива:\n", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf("%i", &arr[i]);

    for (i = 0; i < SIZE; i++)
    {
        if (!contains(res, arr[i], j))
        {
            res[j] = arr[i];
            j++;
        }
    }

    //Вывод результата (массив без повторяющихся элементов)
    printf("Получившийся массив без повторений:\n[ ", j);
    for (i = 0; i < j; i++)
        printf("%i ", res[i]);
    printf("]\n\n");
}