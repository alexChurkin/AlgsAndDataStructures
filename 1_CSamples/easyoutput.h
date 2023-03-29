#include <stdio.h>
#include <string.h>

void ln()
{
    printf("\n");
}

void print(char *letters)
{
    printf("%s", letters);
}

void println(char *letters)
{
    printf("%s\n", letters);
}

void print_char(char c)
{
    printf("%c", c);
}

void print_int(int a)
{
    printf("%i", a);
}

void print_float(float a)
{
    printf("%f", a);
}

void print_double(double a)
{
    printf("%lf", a);
}

void str_reverse(char someString[])
{
    char buff;
    int lastIndex = strlen(someString) - 1;
    int i = 0;
    //print("\nreverse: string length = ");
    //printInt(lastIndex);

    while (i < lastIndex - i)
    {
        buff = someString[lastIndex - i];
        someString[lastIndex - i] = someString[i];
        someString[i] = buff;
        //print("\nreverse: iteration");
        i++;
    }
    //print("\nreverse: finish");
}