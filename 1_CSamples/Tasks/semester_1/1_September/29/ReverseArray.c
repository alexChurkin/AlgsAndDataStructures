#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>
#include <locale.h>

/*
5. Инвертировать заданный массив случайных чисел
*/
void reverse(int arr[])
{
    int buff;
    int lastIndex = SIZE - 1;
    int i = 0;

    while (i < lastIndex - i)
    {
        buff = arr[lastIndex - i];
        arr[lastIndex - i] = arr[i];
        arr[i] = buff;
        i++;
    }
}

void main()
{
    setlocale(LC_ALL, "");
    int i;
    int arr[SIZE];
    //Считывание
    for (i = 0; i < SIZE; i++)
        scanf("%i", &arr[i]);

    reverse(arr);

    //Вывод
    printf("Результат:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%i ", arr[i]);
    }
}