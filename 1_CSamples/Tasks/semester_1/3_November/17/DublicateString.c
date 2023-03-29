#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*
3. Функция дублирования (копирования) строки
*/
char *copy_string(char *str)
{
    //Воспользуемся strlen из стандартной библиотеки string.h
    int len = strlen(str);
    char *new = (char *)malloc(len + 1);

    int i = 0;
    while (str[i] != '\0')
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return new;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    char str[] = "This is a string";
    char *copy = copy_string(str);
    printf(copy);
}