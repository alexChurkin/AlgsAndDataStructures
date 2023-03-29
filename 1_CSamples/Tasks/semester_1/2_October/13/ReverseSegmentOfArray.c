#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
7. Проинвертировать отрезок массива от наибольшего элемента до наименьшего
   (найти индекс наибольшего; наименьшего элемента в массиве, затем инвертировать
   этот отрезок от наибольшего до наименьшего)
*/

//Получение индекса наибольшего элемента в массиве
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

//Получение индекса наименьшего элемента в массиве
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

//Переворот сегмента массива от одного индекса до другого
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

    printf("startIndex = %i\n", startIndex);
    printf("endIndex = %i\n", endIndex);

    int length = endIndex - startIndex + 1;

    for (int i = 0; i < (length / 2); i++)
    {
        temp = arr[i + startIndex];
        arr[i + startIndex] = arr[endIndex - i];
        arr[endIndex - i] = temp;
    }
}

//Вывод массива на экран
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
    int arr[] = {5, 1, 3, 4, 8, 6, 2, 3};
    //При изменении массива важно менять и размер!
    int size = 8;
    reverse_segment(arr, size);
    print_array(arr, size);
}