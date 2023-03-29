#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"

Vector::Vector(int _n)
{
    if (_n <= 0)
        throw TException(__FILE__, __FUNCTION__, __LINE__, "Vector size cannot be <= 0");

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
Vector::Vector(const Vector& v)
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

    double* arr_new = new double[_n];
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
Vector Vector::operator+(const Vector& b)
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

Vector Vector::operator-(const Vector& b)
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

double Vector::operator*(const Vector& b)
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
Vector& Vector::operator=(const Vector& v)
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
Vector& Vector::operator+=(const Vector& v)
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

Vector& Vector::operator-=(const Vector& v)
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
Vector& Vector::operator+=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] += b;

    return *this;
}

Vector& Vector::operator-=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] -= b;

    return *this;
}

Vector& Vector::operator*=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] *= b;

    return *this;
}

Vector& Vector::operator/=(double b)
{
    if(b == 0)
        throw "Division by zero (b = 0)";

    for (int i = 0; i < n; i++)
        arr[i] /= b;

    return *this;
}

double& Vector::operator[](int i)
{
    if (i >= 0 && i < n)
        return arr[i];
    else
        throw "Index out of bounds exception";
}

Vector operator+(double a, const Vector& b)
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

Vector operator-(double a, const Vector& b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = a - c.arr[i];
    }
    return c;
}

Vector operator*(double a, const Vector& b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = a * c.arr[i];
    }
    return c;
}

ostream& operator<<(ostream& os, const Vector& v)
{
    os << '(';
    for (int i = 0; i < v.n - 1; i++)
    {
        os << v.arr[i] << ", ";
    }
    os << v.arr[v.n - 1] << ')';
    return os;
}

istream& operator>>(istream& is, Vector& v)
{
    for (int i = 0; i < v.n; i++)
    {
        is >> v.arr[i];
    }
    return is;
}