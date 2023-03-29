#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
2. Задача. Дан массив A, содержащий n вещественных чисел. Найти индексы k1 и k2 двух элементов массива, расстояние между которыми (|A[k1] – A[k2]|) минимально.
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
    if (size <= 15)
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

typedef struct indices
{
    int k1;
    int k2;
} indices;

indices min_distance_indices(double a[], int n)
{
    indices answer = {0, 0};
    if (n <= 1)
        return answer;
    answer.k2 = 1;

    double distance = fabs(a[0] - a[1]);
    double temp_d;
    int i, j;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            temp_d = fabs(a[i] - a[j]);
            if (temp_d < distance)
            {
                distance = temp_d;
                answer.k1 = i;
                answer.k2 = j;
            }
        }
    return answer;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    int *array = get_array(&n);
    indices ind = min_distance_indices(array, n);
    printf("%i %i", ind.k1, ind.k2);
}