#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

/*
2. Класс комплексное число
*/
class complex
{
private:
    double re, im;

public:
    //Конструктор по умолчанию
    complex()
    {
        this->re = 0.0;
        this->im = 0.0;
    }

    //Конструктор с параметрами
    complex(double re, double im)
    {
        this->re = re;
        this->im = im;
    }

    //Сеттер действительной части
    void set_re(double re)
    {
        this->re = re;
    }

    //Геттер действительной части
    double get_re()
    {
        //по факту return this->re;
        return re;
    }

    //Сеттер мнимой части
    void set_im(double im)
    {
        this->im = im;
    }

    //Геттер мнимой части
    double get_im()
    {
        return im;
    }

    /* .................................... */

    //1. complex + complex (+)
    complex operator+(const complex b)
    {
        complex c;
        c.re = re + b.re;
        c.im = im + b.im;
        return c;
    }

    //2. complex + double (+)
    complex operator+(const double b)
    {
        complex c;
        c.re = re + b;
        c.im = im;
        return c;
    }

    //3. double + complex (+)
    friend complex operator+(const double d, complex c)
    {
        c.re += d;
        return c;
    }

    //4. complex += complex (+)
    void operator+=(const complex b)
    {
        re += b.re;
        im += b.im;
    }

    //5. complex += double (+)
    void operator+=(const double b)
    {
        re += b;
    }

    /* .................................... */
    //1. comp - comp (+)
    complex operator-(const complex b)
    {
        complex c;
        c.re = re - b.re;
        c.im = im - b.im;
        return c;
    }

    //2. complex - double (+)
    complex operator-(const double b)
    {
        complex c;
        //равносильно this->re
        c.re = re - b;
        c.im = im;
        return c;
    }

    //3. double - complex (+)
    friend complex operator-(const double d, complex c)
    {
        c.re = d - c.re;
        c.im = -c.im;
        return c;
    }

    //4. comp -= comp (+)
    void operator-=(const complex b)
    {
        re -= b.re;
        im -= b.im;
    }

    //5. complex -= double (+)
    void operator-=(const double b)
    {
        re -= b;
    }

    /* .................................... */

    //1. complex * complex (+)
    complex operator*(const complex b)
    {
        complex c;
        c.re = re * b.re - im * b.im;
        c.im = re * b.im + im * b.re;
        return c;
    }

    //2. complex * double (+)
    complex operator*(const double b)
    {
        complex c;
        c.re = b * re;
        c.im = b * im;
        return c;
    }

    //3. double * complex (+)
    friend complex operator*(const double b, complex c)
    {
        c.re *= b;
        c.im *= b;
        return c;
    }

    //4. complex *= complex (+)
    void operator*=(const complex b)
    {
        double newre = re * b.re - im * b.im;
        double newim = re * b.im + im * b.re;
        re = newre;
        im = newim;
    }

    //5. complex *= double (+)
    void operator*=(const double b)
    {
        re *= b;
        im *= b;
    }

    /*
    Возвращает комплексно-сопряжённое к данному число
    const в данном случае сообщает о том, что данная функция
    не затрагивает внутренности нашего текущего объекта
    -> может быть вызвана у константного объекта
    (как в случае с делением)
    */
    complex conjugate() const
    {
        return complex(re, -im);
    }

    //1. complex / complex (+)
    complex operator/(const complex b)
    {
        complex c = (*this) * b.conjugate();
        double t = b.re * b.re + b.im * b.im;
        c.re /= t;
        c.im /= t;
        return c;
    }

    //2. complex / double (+)
    complex operator/(const double b)
    {
        complex c;
        c.re = re / b;
        c.im = im / b;
        return c;
    }

    //3. double / complex
    friend complex operator/(const double b, complex c)
    {
        complex _b = complex(b, 0);
        //А далее делим как _b на c
        complex cc = (_b)*c.conjugate();
        double t = c.re * c.re + c.im * c.im;
        cc.re /= t;
        cc.im /= t;
        return cc;
    }

    //4. complex /= complex
    void operator/=(const complex b)
    {
        complex c = (*this) * b.conjugate();
        double t = b.re * b.re + b.im * b.im;
        c.re /= t;
        c.im /= t;
        re = c.re;
        im = c.im;
    }

    //5. complex /= double
    void operator/=(const double b)
    {
        re /= b;
        im /= b;
    }

    double abs()
    {
        return sqrt(re * re + im * im);
    }

    static string get_str(complex c)
    {
        if (c.im == 0)
            return to_string(c.re);
        else if (c.im > 0)
        {
            return to_string(c.re) + " + " + to_string(c.im) + "i";
        }
        else
        {
            return to_string(c.re) + " - " + to_string(-c.im) + "i";
        }
    }

    //Для вывода в cout (переопределение <<)
    //ostream - базовый класс для всех выходных потоков
    friend ostream &operator<<(ostream &os, complex c)
    {
        os << get_str(c);
        return os;
    }

    //Для считывания в cin (переопределение >>)
    //ostream - базовый класс для всех выходных потоков
    friend istream &operator>>(istream &is, complex &c)
    {
        string str;
        //Чтение из потока
        getline(is, str);

        //Найдём позицию плюса в строке
        int sign_pos = -1;
        char sign = 1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '+')
            {
                sign_pos = i;
                break;
            }
            else if (str[i] == '-')
            {
                sign_pos = i;
                sign = -1;
                break;
            }
        }
        c.re = stod(str.substr(0, sign_pos - 1));
        c.im = sign * stod(str.substr(sign_pos + 1, str.size() - 1));
        return is;
    }
};

int main()
{
    setlocale(LC_ALL, "russian");
    complex a(1, 2);
    complex b(3, 4);
    double d = 10;

    //Тесты сложения (+, +=)
    cout << "> Сложение cmp + cmp:     a + b = " << (a + b) << '\n';
    cout << "> Сложение cmp + double:  a + d = " << (a + d) << '\n';
    cout << "> Сложение double + cmp:  d + a = " << (d + a) << '\n';
    a += b;
    cout << "> Сложение cmp += cmp:    a += b = " << a << '\n';
    a += d;
    cout << "> Сложение cmp += double: a += d = " << a << "\n\n";

    a.set_re(1);
    a.set_im(2);
    b.set_re(3);
    b.set_im(4);

    //Тесты вычитания (-, -=)
    cout << "> Вычитание cmp - cmp:     a - b = " << (a - b) << '\n';
    cout << "> Вычитание cmp - double:  a - d = " << (a - d) << '\n';
    cout << "> Вычитание double - cmp:  d - a = " << (d - a) << '\n';
    a -= b;
    cout << "> Вычитание cmp -= cmp:    a -= b = " << a << '\n';
    a -= d;
    cout << "> Вычитание cmp -= double: a -= d = " << a << "\n\n";

    a.set_re(1);
    a.set_im(2);
    b.set_re(3);
    b.set_im(4);

    //Тесты умножения (*, *=)
    cout << "> Умножение cmp * cmp:     a * b = " << (a * b) << '\n';
    cout << "> Умножение cmp * double:  a * d = " << (a * d) << '\n';
    cout << "> Умножение double * cmp:  d * a = " << (d * a) << '\n';
    a *= b;
    cout << "> Умножение cmp *= cmp:    a *= b = " << a << '\n';
    a *= d;
    cout << "> Умножение cmp *= double: a *= d = " << a << "\n\n";

    a.set_re(1);
    a.set_im(2);
    b.set_re(3);
    b.set_im(4);

    //Тесты деления (/, /=)
    cout << "> Деление cmp / cmp:     a / b = " << (a / b) << '\n';
    cout << "> Деление cmp / double:  a / d = " << (a / d) << '\n';
    cout << "> Деление double / cmp:  d / a = " << (d / a) << '\n';
    a /= b;
    cout << "> Деление cmp /= cmp:    a /= b = " << a << '\n';
    a /= d;
    cout << "> Деление cmp /= double: a /= d = " << a << "\n\n";

    a.set_re(1);
    a.set_im(2);
    b.set_re(3);
    b.set_im(4);

    cout << "> Модуль:   |a| = " << a.abs() << '\n';
    cout << "> Введите комплексное число: ";
    complex k;
    cin >> k;
    cout << "Вы ввели " << k;
    return 0;
}