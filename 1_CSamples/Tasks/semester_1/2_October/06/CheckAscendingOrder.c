#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 5

/*
2. Задан массив размера SIZE (с клавиатуры).
   Определить, является ли он упорядоченным по возрастанию.
*/
void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[SIZE];
    //F = 1 означает, что мы по умолчанию считаем массив отсортированным верным образом
    int i = 0, F = 1;

    //Заполнение массива с клавиатуры
    while (i < SIZE)
        scanf("%i", &arr[i++]);
    for (i = 1; i < SIZE; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            F = 0;
            break;
        }
    }
    if (F)
        printf("Массив корректно отсортирован по возрастанию");
    else
        printf("Массив НЕ отсортирован по возрастанию");
}