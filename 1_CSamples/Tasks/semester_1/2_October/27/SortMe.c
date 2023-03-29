#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
Сортировки (Universal program)
*/

//Основные функции для сортировки
void shaker_sort(int arr[], int size, int *comp_count, int *swap_count);
void selection_sort(int arr[], int size, int *comp_count, int *swap_count);
void insertion_sort(int arr[], int size, int *comp_count, int *swap_count, int mode);
void counting_sort(int arr[], int size);
void demonstrate_all(int *arr, int *tmp_arr, int size);

//Вспомогательные функции
int find_insert_position_linearly(int arr[], int right, int *comp_count);
int find_insert_position_binary(int arr[], int right, int *comp_count);
char *is_sorted(int arr[], int size);

void print_menu();
int *get_array(int *newsize);
int *create_empty_array(int size);
int *array_copy(int arr[], int size);
void populate_array(int arr[], int size);
void print_array(int arr[], int size, bool not_big);
void recover_old_array(int *arr, int *tmp_arr, int size);
void swap(int *a, int *b);
int get_min_index(int arr[], int size);
int get_max_index(int arr[], int size);

void main()
{
    setlocale(LC_CTYPE, "rus");

    int menu_number;
    int *arr = NULL;
    int *tmp_arr = NULL;
    int size;
    int comp_count, swap_count;

    print_menu();
    arr = get_array(&size);
    tmp_arr = array_copy(arr, size);

    while (1)
    {
        scanf("%i", &menu_number);
        switch (menu_number)
        {
        case 1:
            free(arr);
            free(tmp_arr);
            arr = get_array(&size);
            tmp_arr = array_copy(arr, size);
            break;
        case 2:
            print_array(arr, size, false);
            break;
        case 3:
            shaker_sort(arr, size, &comp_count, &swap_count);
            printf("Шейкерная сортировка:\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                   is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 4:
            selection_sort(arr, size, &comp_count, &swap_count);
            printf("Сортировка выбором:\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                   is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 5:
            insertion_sort(arr, size, &comp_count, &swap_count, 2);
            printf("Сортировка вставками (с бин. поиском):\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                   is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 6:
            counting_sort(arr, size);
            print_array(arr, size, false);
            printf("Корректность - %s\n", is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 7:
            demonstrate_all(arr, tmp_arr, size);
            break;
        case 8:
            print_menu();
            break;
        }
    }
}

void shaker_sort(int arr[], int size, int *comp_count, int *swap_count)
{
    int l = 0, r = size - 1;
    bool sorted = false;
    (*comp_count) = 0;
    (*swap_count) = 0;

    while (!sorted)
    {
        sorted = true;
        for (int i = l; i < r; i++)
        {
            (*comp_count)++;
            if (arr[i] > arr[i + 1])
            {
                (*swap_count)++;
                swap(&arr[i], &arr[i + 1]);
                sorted = false;
            }
        }
        r--;
        for (int i = r; i > l; i--)
        {
            (*comp_count)++;
            if (arr[i - 1] > arr[i])
            {
                (*swap_count)++;
                swap(&arr[i - 1], &arr[i]);
                sorted = false;
            }
        }
        l++;
    }
}

void selection_sort(int arr[], int size, int *comp_count, int *swap_count)
{
    int i, j, pos;
    (*comp_count) = 0;
    (*swap_count) = 0;

    for (i = 0; i < size; i++)
    {
        pos = i;
        //Находим позицию минимального эл-та в неотсортированной части массива
        for (j = i; j < size; j++)
        {
            (*comp_count)++;
            if (arr[j] < arr[pos])
                pos = j;
        }
        //Перемещаем его в конец отсортированной части
        (*swap_count)++;
        swap(&arr[pos], &arr[i]);
    }
}

void insertion_sort(int arr[], int size, int *comp_count, int *swap_count, int mode)
{
    //TODO Сортировка вставками
    int i, j, pos, tmp;
    (*comp_count) = 0;
    (*swap_count) = 0;

    for (i = 1; i < size; i++)
    {
        pos = (mode == 1) ? find_insert_position_linearly(arr, i, comp_count)
                          : find_insert_position_binary(arr, i, comp_count);
        //Сдвигаем все элементы от конца к началу
        tmp = arr[i];
        for (j = i; j > pos; j--)
        {
            (*swap_count)++;
            arr[j] = arr[j - 1];
        }
        (*swap_count)++;
        arr[pos] = tmp;
    }
}

void counting_sort(int arr[], int size)
{
    int arr_min = arr[get_min_index(arr, size)];
    int arr_max = arr[get_max_index(arr, size)];
    int new_size = arr_max - arr_min + 1;
    int *count = create_empty_array(new_size);
    int i, j, cur = arr_min, i_in_arr = 0;

    //Обнуление элементов временного массива (для подсчётов)
    for (i = 0; i < new_size; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[arr[i] - arr_min]++;

    for (i = 0; i < new_size; i++)
    {
        for (j = 0; j < count[cur - arr_min]; j++)
        {
            arr[i_in_arr] = cur;
            i_in_arr++;
        }
        cur++;
    }
    //Освобождение памяти, выделенной для "подсчётов"
    free(count);
}

void demonstrate_all(int *arr, int *tmp_arr, int size)
{
    time_t begin, end;
    int comp_count, swap_count;

    begin = clock();
    shaker_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> Шейкерная:                     t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
           ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    begin = clock();
    selection_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> Выбором:                       t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
           ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 1);
    end = clock();
    printf("> Вставками 1 (с лин. поиском):  t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
           ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 2);
    end = clock();
    printf("> Вставками 2 (с бин. поиском):  t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
           ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    begin = clock();
    counting_sort(arr, size);
    end = clock();
    printf("> Подсчётом:                     t = %f сек., корректность - %s\n",
           ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
}

/* ........................  <Вспомогательные функции> ........................  */
int find_insert_position_linearly(int arr[], int right, int *comp_count)
{
    int j, pos = right;
    for (j = 0; j < right; j++)
    {
        (*comp_count)++;
        if (arr[right] <= arr[j])
        {
            pos = j;
            break;
        }
    }
    return pos;
}

int find_insert_position_binary(int arr[], int right, int *comp_count)
{
    int l = 0, r = right - 1, c;
    while (l <= r)
    {
        c = (l + r) / 2;
        (*comp_count)++;
        if (arr[right] < arr[c])
            r = c - 1;
        else
            l = c + 1;
    }
    return r + 1;
}

char *is_sorted(int arr[], int size)
{
    int i;
    for (i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
            return "НЕТ!!!";
    }
    return "ДА";
}

/* ........................ <Вспомогательные функции 2> ...................... */
void print_menu()
{
    printf("Доступные команды:\n");
    printf("---------------------------\n");
    printf("1. Создать/пересоздать массив\n");
    printf("2. Отобразить текущий массив\n");
    printf("3. Произвести шейкерную сортировку\n");
    printf("4. Произвести сортировку выбором\n");
    printf("5. Произвести сортировку вставками\n");
    printf("6. Произвести сортировку подсчётом\n");
    printf("7. Сравнить скорость сортировок (3, 4, 5 и 6)\n");
    printf("8. Отобразить меню команд\n");
    printf("0. Завершить программу\n");
    printf("---------------------------\n\n");
}

int *get_array(int *size)
{
    printf("Введите размер нового массива: ");
    scanf("%i", size);
    int *arr = create_empty_array(*size);
    populate_array(arr, *size);
    return arr;
}

int *create_empty_array(int size)
{
    return (int *)malloc(size * sizeof(int));
}

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

void populate_array(int arr[], int size)
{
    if (size <= 5)
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
        printf("Успешно сгенерирован новый массив.\n");
        print_array(arr, size, true);
    }
}

void print_array(int arr[], int size, bool not_big)
{
    //Не печатаем на экран массив слишком большого размера!
    if (not_big && size > 150)
        return;

    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("%i]\n", arr[size - 1]);
}

void recover_old_array(int *arr, int *tmp_arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = tmp_arr[i];
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int get_min_index(int arr[], int size)
{
    int index = 0, i;
    for (int i = 0; i < size; i++)
        if (arr[i] < arr[index])
            index = i;
    return index;
}

int get_max_index(int arr[], int size)
{
    int index = 0, i;
    for (int i = 0; i < size; i++)
        if (arr[i] > arr[index])
            index = i;
    return index;
}
/* ........................ </Вспомогательные функции 2> ...................... */