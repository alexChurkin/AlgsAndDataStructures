#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
1. Подсчёт длины строки
*/
int str_length(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    char str[] = "Some str";
    printf("length = %i", str_length(str));
}