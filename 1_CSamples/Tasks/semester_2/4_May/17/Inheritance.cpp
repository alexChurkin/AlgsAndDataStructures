#include <iostream>
#include <fstream>
#include <clocale>
#include <cmath>
#include <ctime>
#include <string>
#define SIZE 3
using namespace std;

/*
1. Наследование (пример - геометрические объекты)
*/
class Figure
{
    //Доступен и потомкам
protected:
    int color;

public:
    Figure(int _color = 0) : color(_color)
    {
    }

    int &getColor()
    {
        return color;
    }

    //Чисто виртуальный метод
    //Класс стал абстрактным, т.к. нет реализации методов area и perimeter
    virtual double area() = 0;

    virtual double perimeter() = 0;

    virtual void print() = 0;
};

class Rectangle : public Figure
{
protected:
    double a, b;

public:
    Rectangle(double _a = 1, double _b = 1, int _color = 0)
        : Figure(_color), a(_a), b(_b)
    {
    }

    double &getA()
    {
        return a;
    }

    double &getB()
    {
        return b;
    }

    //Площадь (переопределена)
    double area()
    {
        return a * b;
    }

    //Периметр (переопределён)
    double perimeter()
    {
        return 2 * (a + b);
    }

    void print()
    {
        cout << "Rectangle: a = " << a << ", b = "
             << b << ", color = " << color << '\n';
    }
};

class Square : public Rectangle
{
public:
    Square(double _a, int _color) : Rectangle(_a, _a, _color)
    {
    }

    void print()
    {
        cout << "Square: a = " << a << ", b = "
             << b << ", color = " << color << '\n';
    }
};

class Triangle : public Figure
{
protected:
    double a, b, c;

public:
    Triangle(double _a, double _b, double _c, int _color)
        : Figure(_color), a(_a), b(_b), c(_c)
    {
    }

    double perimeter()
    {
        return a + b + c;
    }

    double area()
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void print()
    {
        cout << "Triangle: a = " << a << ", b = " << b << ", c = " << c
             << ", color = " << color << '\n';
    }
};

class EquilateralTriangle : Triangle
{
    EquilateralTriangle(double _a, double _b, int color)
        : Triangle(_a, _b, _b, color)
    {
    }

    void print()
    {
        cout << "EquilateralTriangle: a = " << a << ", b = " << b << ", c = " << c
             << ", color = " << color << '\n';
    }
};

int main()
{
    setlocale(LC_ALL, "russian");

    //Массив фигур (только фигуры, не предки)
    //Figure arr[10];
    //Указатели на базовый класс. Указателю на базовый класс может
    //быть присвоен указатель на один из производных классов!
    Figure *arr[SIZE];
    //так писать можно, но не стоит
    //arr[0] = &t;
    //Лучше динамическая память. Треугольник исчезнет при удалении массива,
    //А не при завершении нашей функции, в которой это всё происходит
    arr[0] = new Rectangle(5, 10, 1);
    arr[1] = new Square(15, 2);
    arr[2] = new Triangle(3, 4, 5, 3);

    for (int i = 0; i < SIZE; i++)
    {
        arr[i]->print();
        cout << "Area = " << arr[i]->area() << '\n';
        cout << "Perimeter = " << arr[i]->perimeter() << "\n\n";
    }
    return 0;
}