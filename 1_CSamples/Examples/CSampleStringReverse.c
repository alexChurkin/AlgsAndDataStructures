#include "D:\Projects\CVSCode\easyoutput.h"
#include <string.h>

void reverse(char *someString)
{
    char buff;
    int lastIndex = strlen(someString) - 1;
    int i = 0;
    //print("\nreverse: string length = ");

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

void main()
{
    char someString[] = "haeeey";
    reverse(someString);
    println(someString);
}