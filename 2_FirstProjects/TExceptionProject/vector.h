#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
#include "texception.h"
using namespace std;

class Vector
{
private:
    int n;
    double* arr;

public:
    //Конструктор обычный
    Vector(int _n = 3);
    //Конструктор копирования
    Vector(const Vector& v);
    //Деструктор
    ~Vector();

    void resize(int _n);

    Vector operator+(const Vector& b);
    Vector operator-(const Vector& b);
    double operator*(const Vector& b);

    Vector operator+(double b);
    Vector operator-(double b);
    Vector operator*(double b);
    Vector operator/(double b);

    //Операторы присваивания
    Vector& operator=(const Vector& b);
    Vector& operator+=(const Vector& b);
    Vector& operator-=(const Vector& b);

    Vector& operator+=(double b);
    Vector& operator-=(double b);
    Vector& operator*=(double b);
    Vector& operator/=(double b);

    //Получение i-й компоненты для чтения/записи (set/get)
    double& operator[](int i);

    //c+v
    friend Vector operator+(double a, const Vector& b);
    //c-v
    friend Vector operator-(double a, const Vector& b);
    //c*v
    friend Vector operator*(double a, const Vector& b);
    //Вывод на экран
    friend ostream& operator<<(ostream& os, const Vector& v);
    //Ввод с клавиатуры
    friend istream& operator>>(istream& is, Vector& v);
};