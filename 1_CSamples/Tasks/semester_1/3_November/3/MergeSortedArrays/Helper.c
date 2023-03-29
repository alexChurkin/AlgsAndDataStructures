#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void print_array(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("%i]\n", arr[size - 1]);
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int *create_empty_array(int size)
{
    return (int *)malloc(size * sizeof(int));
}

void selection_sort(int arr[], int size)
{
    int i, j, pos;
    for (i = 0; i < size; i++)
    {
        pos = i;
        //Находим позицию минимального эл-та в неотсортированной части массива
        for (j = i; j < size; j++)
        {
            if (arr[j] < arr[pos])
                pos = j;
        }
        //Перемещаем его в конец отсортированной части
        swap(&arr[pos], &arr[i]);
    }
}

void populate_array_random(int arr[], int size)
{
    int range_min = 1, range_max = 999;
    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = (double)rand() /
                     (RAND_MAX + 1) * (range_max + 1 - range_min) +
                 range_min;
    }
    selection_sort(arr, size);
    print_array(arr, size);
}

int *get_array(int *size, int number)
{
    printf("Введите размер массива %i: ", number);
    scanf("%i", size);
    int *arr = create_empty_array(*size);
    populate_array_random(arr, *size);
    return arr;
}