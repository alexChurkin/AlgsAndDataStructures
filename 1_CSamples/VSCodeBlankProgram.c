#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
Заготовка для консольной программы на C В Visual Studio
*/
void main()
{
    setlocale(LC_CTYPE, "rus");
    
}
//Для VS Code с расширением Code Runner и GCC (команда для компиляции кода на C):
//cd $dir && gcc -finput-charset=UTF-8 -fexec-charset=cp1251 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt
//Те же самые флаги для gcc в принципе:
// -finput-charset=UTF-8 -fexec-charset=cp1251