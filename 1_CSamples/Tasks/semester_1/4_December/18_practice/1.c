#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>

/*
1. Задача. Дан массив A, содержащий n натуральных чисел. Проверить, образуют ли его элементы арифметическую прогрессию.
*/
//Красивая печать массива
void print_array(int arr[], int size)
{
    printf("[");
    if (size <= 50)
    {
        for (int i = 0; i < size - 1; i++)
            printf("%i, ", arr[i]);
    }
    else
    {
        for (int i = 0; i < 10; i++)
            printf("%i, ", arr[i]);
        printf("... , ");
        for (int i = size - 10; i < size - 1; i++)
            printf("%i, ", arr[i]);
    }
    printf("%i]\n", arr[size - 1]);
}

//Удобное создание динамического массива (сменить тип, если нужно)
int *create_empty_array(int size)
{
    return (int *)malloc(size * sizeof(int));
}

/*......<Крутейшее получение массива с клавиатуры или рандомно>......*/
void populate_array(int arr[], int size)
{
    if (size <= 20)
    {
        printf("Введите %i чисел\n", size);
        for (int i = 0; i < size; i++)
            scanf("%i", &arr[i]);
    }
    else
    {
        int range_min, range_max;
        srand((unsigned int)time(NULL));
        printf("Введите минимальное значение: ");
        scanf("%i", &range_min);
        printf("Введите максимальное значение: ");
        scanf("%i", &range_max);
        for (int i = 0; i < size; i++)
        {
            arr[i] = (double)rand() /
                         (RAND_MAX + 1) * (range_max + 1 - range_min) +
                     range_min;
        }
        printf("Успешно сгенерирован новый массив:\n");
        print_array(arr, size);
    }
}

int *get_array(int *size)
{
    printf("Введите размер нового массива: ");
    scanf("%i", size);
    int *arr = create_empty_array(*size);
    populate_array(arr, *size);
    return arr;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int *array_copy(int arr[], int size)
{
    int *new_arr, i;
    new_arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

int is_progression(int a[], int n)
{
    //Если размер меньше или равен 2-м, то проверять нечего
    if (n <= 2)
        return 1;

    //Можно обойтись без копии, но тогда исходный массив будет испорчен
    int *copy = array_copy(a, n);
    bubble_sort(copy, n);

    int difference = copy[1] - copy[0];

    int i;
    for (i = 1; i < n - 1; i++)
        if (copy[i + 1] - copy[i] != difference) {
            free(copy);
            return 0;
        }
    free(copy);
    return 1;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int size;
    int *array = get_array(&size);
    printf("%i", is_progression(array, size));
}