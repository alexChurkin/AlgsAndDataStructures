#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 5

/* 
6. Задан массив размера SIZE. Сформировать второй массив, 
   i-й элемент которого должен быть равен сумме всех элемеентов первого массива
   от 0 до i
*/
void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[SIZE];
    int res[SIZE];
    int i, j, sum = 0;
    int found = 0;

    printf("Введите %i элементов массива:\n", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf("%i", &arr[i]);

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j <= i; j++)
            sum += arr[j];
        res[i] = sum;
        sum = 0;
    }

    printf("Вывод:\n");
    for (i = 0; i < SIZE; i++)
        printf("%i ", res[i]);
}