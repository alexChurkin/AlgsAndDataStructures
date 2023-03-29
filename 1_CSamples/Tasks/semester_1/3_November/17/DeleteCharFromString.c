#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
/*
2. Удаление конкретного символа из заданной строки
*/
void *delete_char(char *str, char del, char *newstr)
{
    int length = strlen(str);
    //i - счётчик внешний, j - счётчик для newstr
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != del)
        {
            newstr[j] = str[i];
            j++;
        }
        i++;
    }
    newstr[j] = '\0';
}

void main()
{
    setlocale(LC_CTYPE, "rus");

    char str[] = "Hello, world!";
    char newstr[40];

    delete_char(str, 'o', newstr);
    printf(newstr);
}