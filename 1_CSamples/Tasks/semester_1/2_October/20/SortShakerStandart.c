#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

/*
4. Сортировка пузырьком 2 (шейкерная сортировка)
   Замечание: очень важны скобки при инкременте значения по указателю на него (*number)++;
*/
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

//Сама сортировка
void shaker_sort(int arr[], int size, int *compCount, int *exchangesCount)
{
    int l = 0, r = size - 1;
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = l; i < r; i++)
        {
            (*compCount)++;
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                sorted = false;
                (*exchangesCount)++;
                //printArray(arr, size);
            }
        }
        r--;
        for (int i = r; i > l; i--)
        {
            (*compCount)++;
            if (arr[i - 1] > arr[i])
            {
                swap(&arr[i - 1], &arr[i]);
                sorted = false;
                (*exchangesCount)++;
                //printArray(arr, size);
            }
        }
        l++;
    }
}

void main()
{
    setlocale(LC_CTYPE, "rus");

    int size;

    while (1)
    {
        printf("Введите размер массива (< 0 - завершение):\n");
        scanf("%i", &size);
        if (size < 0)
        {
            printf("Завершение.");
        }

        int *pointer = NULL;
        pointer = (int *)malloc(size * sizeof(int));

        if (pointer == NULL)
        {
            printf("Случилось что-то непредвиденное");
            return;
        }

        printf("Введите %i элементов массива:\n", size);
        for (int i = 0; i < size; i++)
            scanf("%i", &pointer[i]);

        int compCount = 0;
        int exchangesCount = 0;
        //Передаём указатели на переменные
        shaker_sort(pointer, size, &compCount, &exchangesCount);
        print_array(pointer, size);
        printf("Сравнений: %i; обменов: %i\n\n", compCount, exchangesCount);
        free(pointer);
    }
}