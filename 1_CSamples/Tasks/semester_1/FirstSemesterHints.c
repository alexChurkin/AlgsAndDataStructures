#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>

/*
1 Семестр
Полезные функции, подсказки для быстрого доступа
*/

//Swap (перемена мест) переменных
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

//Факториал n
int factorial(int n)
{
    int fact = 1;
    int i;
    for (i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

//НОД 2-х целых чисел
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

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
    if (size <= 6)
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
/*......</Крутейшее получение массива с клавиатуры или рандомно>......*/

//Создание копии динамического массива
int *array_copy(int arr[], int size)
{
    int *new_arr, i;
    new_arr = create_empty_array(size);
    for (i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

//Линейный поиск в массиве
int linear_search(int arr[], int size, int element, int *iter_count)
{
    int i;
    for (i = 0; i < size; i++)
    {
        (*iter_count)++;
        if (arr[i] == element)
            return i;
    }
    return -1;
}

//Бинарный поиск в массиве
int binary_search(int arr[], int size, int element, int *iter_count)
{
    int l = 0, r = size - 1;

    while (l <= r)
    {
        (*iter_count)++;
        int c = (l + r) / 2;
        if (element == arr[c])
            return c;
        else if (element < arr[c])
            r = c - 1;
        else
            l = c + 1;
    }
    return -1;
}

//Индекс минимального элемента массива
int get_min_index(int arr[], int size)
{
    int index = 0, i;
    for (int i = 0; i < size; i++)
        if (arr[i] < arr[index])
            index = i;
    return index;
}

//Индекс максимального элемента массива
int get_max_index(int arr[], int size)
{
    int index = 0, i;
    for (int i = 0; i < size; i++)
        if (arr[i] > arr[index])
            index = i;
    return index;
}

//Проверка массива на отсортированность по возрастанию
//можно поменять знак
int check_array_order(int arr[], int size)
{
    int i;
    for (i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return 0;
        }
    }
    return 1;
}

//Реверс (инверсия) элементов массива
void reverse(int arr[], int size)
{
    int buff;
    int lastIndex = size - 1;
    int i = 0;

    while (i < lastIndex - i)
    {
        buff = arr[lastIndex - i];
        arr[lastIndex - i] = arr[i];
        arr[i] = buff;
        i++;
    }
}

//Пузырёк (стандарт)
void bubble_sort(int arr[], int size)
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
                exchangesCount++;
            }
        }
    }
}

//Слияние двух отсортированных частей массива [l, c], [c + 1, r]
void merge_sorted_parts(
    int arr[], int l, int c, int r,
    int *comp_count, int *swap_count)
{
    int i = l,
        j = c + 1,
        t = 0;
    int *temp_arr;
    temp_arr = (int *)malloc((r - l + 1) * sizeof(int));

    while (i <= c && j <= r)
    {
        (*comp_count)++;
        if (arr[i] <= arr[j])
        {
            temp_arr[t] = arr[i], i++;
        }
        else
        {
            temp_arr[t] = arr[j], j++;
        }
        t++;
    }

    while (i <= c)
    {
        temp_arr[t] = arr[i];
        t++;
        i++;
    }
    while (j <= r)
    {
        temp_arr[t] = arr[j];
        t++;
        j++;
    }

    for (int i = l; i <= r; i++)
    {
        (*swap_count)++;
        arr[i] = temp_arr[i - l];
    }
    free(temp_arr);
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    
}