#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

/*
2. Инверсия отрезка массива с минимального эл-та до максимального
   (на этот раз с динамическим массивом)
*/
int get_max_index(int arr[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

int get_min_index(int arr[], int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    return minIndex;
}

void reverse_segment(int arr[], int size)
{
    int temp;

    int startIndex = get_max_index(arr, size);
    int endIndex = get_min_index(arr, size);

    if (startIndex > endIndex)
    {
        temp = startIndex;
        startIndex = endIndex;
        endIndex = temp;
    }
    else if (startIndex == endIndex)
        return;

    //printf("startIndex = %i\n", startIndex);
    //printf("endIndex = %i\n", endIndex);

    int length = endIndex - startIndex + 1;

    for (int i = 0; i < (length / 2); i++)
    {
        temp = arr[i + startIndex];
        arr[i + startIndex] = arr[endIndex - i];
        arr[endIndex - i] = temp;
    }
}

void print_array(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("%i]\n", arr[size - 1]);
}

void main()
{
    setlocale(LC_CTYPE, "rus");

    while (1)
    {
        int size;
        printf("Введите размер массива (< 0 - завершение работы):\n");
        scanf("%i", &size);
        if (size <= 0)
        {
            printf("Программа завершена.");
            return;
        }
        int *pointer = NULL;
        pointer = (int *)malloc(size * sizeof(int));

        if (pointer == NULL)
        {
            printf("Случилось что-то непредвиденное :(");
            return;
        }

        printf("Введите элементы массива (целые числа):\n");
        for (int i = 0; i < size; i++)
            scanf("%i", &pointer[i]);

        reverse_segment(pointer, size);
        print_array(pointer, size);
        //Освобождаем память
        free(pointer);
    }
}