#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define SIZE 10

/*
3. Быстрая сортировка (сортировка Хоара)
*/

/*
i->     <-j
1 3 1 2 4 ...
*/
void quick_sort(int *arr, int first, int last)
{
    //Вариант проверки 2
    //Если длина сортируемой части меньше 2-х (т.е. <= 1) - стоп
    if(first >= last) return;

    //Центральный элемент
    int el = arr[(first + last) / 2];
    int i = first, j = last;

    //Сортировка относительно элемента el справа и слева
    while (i < j)
    {
        while (arr[i] < el)
            i++;
        while (arr[j] > el)
            j--;
        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    //Вариант проверки 1
    //if (first < j)
        quick_sort(arr, first, j);
    //if (i < last)
        quick_sort(arr, i, last);
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[SIZE] = {5, 3, 5, 2, 7, 1, 8, 600, 200, 100};
    quick_sort(arr, 0, SIZE - 1);

    printf("[");
    for(int i = 0; i < SIZE - 1; i++) {
        printf("%i, ", arr[i]);
    }
    printf("%i]", arr[SIZE - 1]);
}