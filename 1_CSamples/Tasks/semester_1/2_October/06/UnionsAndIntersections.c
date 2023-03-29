#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 5

/*
5. Заданы 2 массива размером SIZE. Сформировать 3-й массив, содержащий
   1 - пересечение
   2 - объединение
   3 - разность первого и второго массива
   Примечание:
   программу также можно сократить, вынеся похожие действия в отдельные функции
*/

int contains(int arrRes[], int element, int limit)
{
    int k;
    for (k = 0; k < limit; k++)
    {
        if (arrRes[k] == element)
            return 1;
    }
    return 0;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr1[SIZE];
    int arr2[SIZE];
    //Для пересечения
    int res1[SIZE];
    int k1 = 0;
    //Для объединения
    int res2_temp[SIZE * 2];
    int res2[SIZE * 2];
    int k2 = 0;
    //Для разности
    int res3[SIZE];
    int k3 = 0;
    int found = 0;

    int i, j;

    printf("Введите элементы 1-го массива:\n");
    for (i = 0; i < SIZE; i++)
        scanf("%i", &arr1[i]);

    printf("Введите элементы 2-го массива:\n");
    for (i = 0; i < SIZE; i++)
        scanf("%i", &arr2[i]);

    /* Пересечение множеств (без повторений!) .......................... */
    for (i = 0; i < SIZE; i++)
    {
        //Поиск в массиве 2 элемента массива 1
        for (j = 0; j < SIZE; j++)
        {
            if (arr1[i] == arr2[j] && !contains(res1, arr1[i], k1))
            {
                res1[k1] = arr1[i];
                k1++;
                break;
            }
        }
    }
    //Вывод
    printf("\nПересечение:\n");
    if (k1 > 0)
        for (i = 0; i < k1; i++)
            printf("%i ", res1[i]);
    else
        printf("[пустое множество]");

    /* Объединение множеств (без повторений!) .......................... */
    //Добовление всех элементов из двух массивов в res2_temp
    for (i = 0; i < SIZE; i++)
    {
        res2_temp[i] = arr1[i];
        res2_temp[i + SIZE] = arr2[i];
    }
    //Избавление от повторений элементов
    for (i = 0; i < 2 * SIZE; i++)
    {
        if (!contains(res2, res2_temp[i], k2))
        {
            res2[k2] = res2_temp[i];
            k2++;
        }
    }
    //Вывод
    printf("\nОбъединение:\n");
    if (k2 > 0)
        for (i = 0; i < k2; i++)
            printf("%i ", res2[i]);
    else
        printf("[пустое множество]");

    /* Разность arr1 - arr2 (если arr2 содержит
       какой-либо элемент, такой же, как и в arr1, то он не добавляется в разность) 
    */
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (arr1[i] == arr2[j])
            {
                found = 1;
                break;
            }
        }
        //Если i-й элемент arr1 не содержится в arr2, то он добавляется в res3 (результат)
        if (!found)
        {
            res3[k3] = arr1[i];
            k3++;
        }
        found = 0;
    }
    //Вывод
    printf("\nРазность:\n");
    if (k3 > 0)
        for (i = 0; i < k3; i++)
            printf("%i ", res3[i]);
    else
        printf("[пустое множество]");
}