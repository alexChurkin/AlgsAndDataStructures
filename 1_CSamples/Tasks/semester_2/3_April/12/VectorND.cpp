#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

/*
1. VectorND
*/
class Vector
{
private:
    int n;
    double *arr;

public:
    //Конструктор обычный
    Vector(int _n = 3);
    //Конструктор копирования
    Vector(const Vector &v);
    //Деструктор
    ~Vector();

    void resize(int _n);

    Vector operator+(const Vector &b);
    Vector operator-(const Vector &b);
    double operator*(const Vector &b);

    Vector operator+(double b);
    Vector operator-(double b);
    Vector operator*(double b);
    Vector operator/(double b);

    //Операторы присваивания
    Vector &operator=(const Vector &b);
    Vector &operator+=(const Vector &b);
    Vector &operator-=(const Vector &b);

    Vector &operator+=(double b);
    Vector &operator-=(double b);
    Vector &operator*=(double b);
    Vector &operator/=(double b);

    //Получение i-й компоненты для чтения/записи (set/get)
    double &operator[](int i);

    //c+v
    friend Vector operator+(double a, const Vector &b);
    //c-v
    friend Vector operator-(double a, const Vector &b);
    //c*v
    friend Vector operator*(double a, const Vector &b);
    //Вывод на экран
    friend ostream &operator<<(ostream &os, const Vector &v);
    //Ввод с клавиатуры
    friend istream &operator>>(istream &is, Vector &v);
};

/* ........................ */

Vector::Vector(int _n)
{
    if (_n <= 0)
        throw "Vector size cannot be <= 0";

    n = _n;
    arr = new double[_n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

//В конструктор копирования передаётся ссылка!
//Иначе будет вызов функции копирования со срабатыванием
//КОНСТРУКТОРА КОПИРОВАНИЯ!!! (БЕСКОНЕЧНЫЙ ЦИКЛ)
//(ссылка является константной для того, чтобы
//случайно не изменить объект)
Vector::Vector(const Vector &v)
{
    n = v.n;
    arr = new double[v.n];
    for (int i = 0; i < n; i++)
        arr[i] = v.arr[i];
}

Vector::~Vector()
{
    delete[] arr;
}

void Vector::resize(int _n)
{
    if (_n == n)
        return;

    double *arr_new = new double[_n];
    for (int i = 0; i < _n; i++)
        arr_new[i] = 0;

    //Новый размер больше старого (просто копируем значения)
    if (_n > n)
        for (int i = 0; i < n; i++)
            arr_new[i] = arr[i];
    //Новый меньше старого (копируем значения, которые уберутся)
    else
        for (int i = 0; i < _n; i++)
            arr_new[i] = arr[i];

    delete[] arr;
    arr = arr_new;
    n = _n;
}

//Блок 1 --------------------------------
Vector Vector::operator+(const Vector &b)
{
    if (n != b.n)
    {
        throw "Vectors have different dimensions";
    }

    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = arr[i] + b.arr[i];
    return res;
}

Vector Vector::operator-(const Vector &b)
{
    if (n != b.n)
    {
        throw "Vectors have different dimensions";
    }

    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = arr[i] - b.arr[i];
    return res;
}

double Vector::operator*(const Vector &b)
{
    if (n != b.n)
    {
        throw "Vectors have different dimensions";
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i] * b.arr[i];
    return sum;
}

//Блок 2 --------------------------------
Vector Vector::operator+(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = (*this)[i] + b;
    //СОЗДАЁТСЯ КОПИЯ ДАННОЙ ПЕРЕМЕННОЙ С ТЕМ ЖЕ ЗНАЧЕНИЕМ,
    //ЗАТЕМ ПЕРЕДАЁТСЯ В ГЛАВНУЮ ПРОГРАММУ! ДЛЯ ЭТОГО ОБЯЗАТЕЛЬНО
    //НУЖНО ПЕРЕОПРЕДЕЛЯТЬ КОНСТРУКТОР КОПИРОВАНИЯ (ЕСЛИ В КЛАССЕ ЕСТЬ
    //ДИНАМИЕЧЕСКИЕ ПОЛЯ)
    //Т.к. иначе деструктор уничтожит память под динамические поля,
    //А в скопированном объекте останется ссылка на них.
    //Стандартно при присваивании происходит побитовое копирование
    //полей, то есть стандартно просто скопируется ссылка,
    //А память уже очистится после завершения этого метода.
    return res;
}

Vector Vector::operator-(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = (*this)[i] - b;
    return res;
}

Vector Vector::operator*(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res.arr[i] = arr[i] * b;
    return res;
}

Vector Vector::operator/(double b)
{
    if (b == 0)
    {
        throw "Division by zero (b = 0)";
    }

    Vector res(n);
    for (int i = 0; i < n; i++)
        res.arr[i] = arr[i] / b;
    return res;
}

//Блок 3 --------------------------------
//Возврат вектора со ссылкой позволяет избежать ошибок с (x = y) = b
Vector &Vector::operator=(const Vector &v)
{
    //Проверка на то, происходит ли присваивание объекта самому себе
    if (this == &v)
        return *this;

    //Если у текущего вектора размер не совпадает с v,
    //то необходимо обновить размер текущего вектора
    //в соответствии с переданным
    if (n != v.n)
    {
        n = v.n;
        delete[] arr;
        arr = new double[n];
    }
    //Далее просто присвоим (скопируем) значения
    for (int i = 0; i < n; i++)
        arr[i] = v.arr[i];

    return *this;
}

//Векторы только одинаковой длины
Vector &Vector::operator+=(const Vector &v)
{
    //Если у текущего вектора размер не совпадает с v,
    //то мы не можем сложить
    if (n != v.n)
    {
        throw "Vectors have different dimensions";
    }

    //Далее просто присвоим (скопируем) значения
    for (int i = 0; i < n; i++)
        arr[i] += v.arr[i];

    return *this;
}

Vector &Vector::operator-=(const Vector &v)
{
    if (n != v.n)
    {
        throw "Vectors have different dimensions";
    }

    for (int i = 0; i < n; i++)
        arr[i] -= v.arr[i];

    return *this;
}

//Блок 4 --------------------------------
Vector &Vector::operator+=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] += b;

    return *this;
}

Vector &Vector::operator-=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] -= b;

    return *this;
}

Vector &Vector::operator*=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] *= b;

    return *this;
}

Vector &Vector::operator/=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] /= b;

    return *this;
}

double &Vector::operator[](int i)
{
    if (i >= 0 && i < n)
        return arr[i];
    else
        throw "Index out of bounds exception";
}

Vector operator+(double a, const Vector &b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] += a;
    }
    //После этого вызывается конструктор копирования в вызывающей
    //функции
    return c;
}

Vector operator-(double a, const Vector &b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = a - c.arr[i];
    }
    return c;
}

Vector operator*(double a, const Vector &b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = a * c.arr[i];
    }
    return c;
}

ostream &operator<<(ostream &os, const Vector &v)
{
    os << '(';
    for (int i = 0; i < v.n - 1; i++)
    {
        os << v.arr[i] << ", ";
    }
    os << v.arr[v.n - 1] << ')';
    return os;
}

istream &operator>>(istream &is, Vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        is >> v.arr[i];
    }
    return is;
}

/* ........................ */
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
    catch (const char *str)
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
    catch (const char *str)
    {
        cout << "Произошла ошибка: " << str << '\n';
    }

    //Некорректное создание вектора
    try
    {
        Vector t4(-15);
    }
    catch (const char *str)
    {
        cout << "Произошла ошибка: " << str << '\n';
    }
    return 0;
}