#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
Чуркин Александр 382006-2
Задания 1-4 22.12.2020
*/

//1
int is_alternate_sequence(int a[], int size)
{
    int i, is_even, cur_is_even;
    if (size <= 1)
        return 0;

    is_even = a[0] % 2 == 0;
    for (i = 1; i < size; i++)
    {
        cur_is_even = a[i] % 2 == 0;
        if (cur_is_even == is_even)
            return i;
        is_even = cur_is_even;
    }
    return 0;
}

//2
int digits_count(char *str)
{
    int i, answer = 0;
    for (i = 0; i < strlen(str); i++)
        if (str[i] >= '0' && str[i] <= '9')
            answer++;
    return answer;
}

//3
char *dublicate_char(char *str, char c)
{
    char *new_str;
    int size = strlen(str);
    int new_size = size + 1;
    int i, j;
    for (i = 0; i < size; i++)
        if (str[i] == c)
            new_size++;

    new_str = (char *)malloc(new_size * sizeof(char));

    for (i = 0, j = 0; i < new_size; i++)
    {
        if (str[i] == c)
            new_str[j++] = new_str[j++] = c;
        else
            new_str[j++] = str[i];
    }
    new_str[j] = '\0';
    return new_str;
}

//4
char *remove_latest_substr(char *s, char *s0)
{
    int size = strlen(s);
    int s0size = strlen(s0);

    if (size == 0 || s0size == 0)
        return s;

    //Индексы начала и конца вхождения подстроки
    int start = -1, end = -1;
    int tstart = -1;

    int i, j;
    for (i = 0, j = 0; i < size; i++)
    {
        if (s[i] == s0[j])
        {
            if (j == 0)
                tstart = i;
            j++;

            //Найдено одно из вхождений
            if (j == s0size)
            {
                start = tstart, end = i;
                j = 0;
            }
        }
        else
        {
            j = 0;
            if (s[i] == s0[j])
            {
                tstart = i;
                j++;
            }
            if (j == s0size)
            {
                start = tstart, end = i;
                j = 0;
            }
        }
    }

    if (end != -1)
    {
        //printf("\n%i %i\n", start, end);
        int last = size - i;
        for (i = start; i + s0size < size; i++)
        {
            s[i] = s[i + s0size];
        }
        s[i] = '\0';
    }

    return s;
}

void main()
{
    setlocale(LC_CTYPE, "rus");

    printf("Задача 1:\n");
    //Ответ: 0
    int a1[] = {1, 2, 3, 4, 5, 6};
    printf("%i ", is_alternate_sequence(a1, 6));
    //Ответ: 2
    int a2[] = {1, 2, 4, 5, 6, 7};
    printf("%i ", is_alternate_sequence(a2, 6));
    //Ответ: 1
    int a3[] = {1, 5, 6, 7, 8, 9};
    printf("%i", is_alternate_sequence(a3, 6));

    printf("\n-----------------\n");
    printf("Задача 2:\n");
    //Ответ 10
    printf("%i ", digits_count("0123456789"));
    //Ответ 3
    printf("%i ", digits_count("123"));
    //Ответ 0
    printf("%i", digits_count("Просто строка без цифр"));

    printf("\n-----------------\n");
    printf("Задача 3:\n");
    //Ответ sstr_sstr
    printf("%s ", dublicate_char("str_str", 's'));
    //Ответ 333333
    printf("%s ", dublicate_char("333", '3'));
    //Ответ the_same
    printf("%s ", dublicate_char("the_same", 'k'));

    printf("\n-----------------\n");
    printf("Задача 4:\n");

    //Ответ window10s
    char s1[] = "window1dow0s";
    printf("%s ", remove_latest_substr(s1, "dow"));

    //Ответ o
    char s2[] = "hello";
    printf("%s ", remove_latest_substr(s2, "hell"));

    //Ответ simplestring
    char s3[] = "simplestring";
    printf("%s ", remove_latest_substr(s3, "something"));
}