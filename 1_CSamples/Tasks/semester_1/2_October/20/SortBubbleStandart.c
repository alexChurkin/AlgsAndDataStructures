#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
3. Сортировка пузырьком (стандартная)
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
int *bubble_sort(int arr[], int size)
{
    int compCount = 0;
    int exchangesCount = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            compCount++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                //printArray(arr, size);
                exchangesCount++;
            }
        }
    }
    int *p = (int *)malloc(2 * sizeof(int));
    p[0] = compCount;
    p[1] = exchangesCount;
    return p;
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

        int *resultInfo = bubble_sort(pointer, size);
        print_array(pointer, size);
        printf("Сравнений: %i; обменов: %i\n\n", resultInfo[0], resultInfo[1]);
        free(pointer);
        free(resultInfo);
    }
}