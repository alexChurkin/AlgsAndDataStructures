#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
#include "vector.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    //v1 = (1, 2, 3)
    //v2 = (5, 5, 5)
    Vector v1(3);
    Vector v2(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v2[0] = v2[1] = v2[2] = 5;

    cout << "Дано:\n";
    cout << "========================\n";
    cout << "v1 = " << v1 << "\n";
    cout << "v2 = " << v2 << "\n";
    cout << "========================\n\n";

    //////////////////////////////////////
    Vector test1 = v1 + v2;
    cout << "v1 + v2 = " << test1 << '\n';

    Vector test2 = v1 - v2;
    cout << "v1 - v2 = " << test2 << '\n';

    double test3 = v1 * v2;
    cout << "v1 * v2 = " << test3 << '\n';
    //////////////////////////////////////
    Vector test4 = v1 + 1;
    cout << "v1 + 1 = " << v1 + 1 << '\n';

    Vector test5 = v1 - 1;
    cout << "v1 - 1 = " << v1 - 1 << '\n';

    Vector test6 = v1 * 2;
    cout << "v1 * 2 = " << v1 * 2 << '\n';

    Vector test7 = v1 / 2;
    cout << "v1 / 2 = " << v1 / 2 << '\n';
    //////////////////////////////////////
    Vector test8 = v1;
    cout << "test8  = v1          || = " << test8 << '\n';

    Vector test9 = (v1 += v2);
    cout << "test9  = (v1 += v2)  || = " << test9 << '\n';

    Vector test10 = (v1 -= v2);
    cout << "test10 = (v1 -= v2)  || = " << test10 << '\n';
    //////////////////////////////////////
    Vector test11 = (v1 += 2);
    cout << "test11 = (v1 += 2)   || = " << test11 << '\n';

    Vector test12 = (v1 -= 2);
    cout << "test12 = (v1 -= 2)   || = " << test12 << '\n';

    Vector test13 = (v1 *= 2);
    cout << "test13 = (v1 *= 2)   || = " << test13 << '\n';

    Vector test14 = (v1 /= 2);
    cout << "test14 = (v1 /= 2)   || = " << test14 << '\n';

    Vector test15 = 1 + v1;
    cout << "1 + v1 = " << test15 << '\n';

    Vector test16 = 1 - v1;
    cout << "1 - v1 = " << test16 << '\n';

    Vector test17 = 2 * v1;
    cout << "2 * v1 = " << test17 << "\n\n";

    Vector test18(5);
    test18[0] = 10;
    test18[1] = 20;
    test18[2] = 30;
    test18[3] = 40;
    test18[4] = 50;
    cout << "Создан вектор            test18 = " << test18 << '\n';
    test18.resize(8);
    cout << "Изменён его размер на 8: test18 = " << test18 << '\n';
    test18.resize(3);
    cout << "Изменён его размер на 3: test18 = " << test18 << "\n\n";

    //........Демонстрация ловли исключений........
    //Некорректное обращение []
    try
    {
        double a = test17[10];
    }
    catch (const char* str)
    {
        cout << "Произошла ошибка: " << str << '\n';
    }

    //Некорректная сумма
    Vector t1(3);
    Vector t2(4);
    try
    {
        Vector t3 = t1 + t2;
    }
    catch (const char* str)
    {
        cout << "Произошла ошибка: " << str << '\n';
    }

    //Некорректное создание вектора
    try
    {
        Vector t4(-15);
    }
    catch (TException e)
    {
        cout << e;
    }
    return 0;
}