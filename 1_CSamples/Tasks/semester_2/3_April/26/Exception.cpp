#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cstring>
using namespace std;

//Цель класса - хранить и передавать на обработку информацию
class TException
{
private:
    char *file; //Имя файла
    char *func; //Имя функции
    int line;   //Номер строки
    char *desc; //Подробное описание

public:
    //Обычный конструктор
    TException(char *_file, char *_func, int _line, char *_desc)
    {
        //Встроенные функции
        //n + 1, чтобы хватило места на нулевой символ
        //strcpy работает только тогда, когда обе строки инициализированы
        int n1 = strlen(_file);
        file = new char[n1 + 1];
        strcpy(file, _file);

        int n2 = strlen(_func);
        func = new char[n2 + 1];
        strcpy(func, _func);

        int n3 = strlen(_desc);
        desc = new char[n3 + 1];
        strcpy(desc, _desc);

        line = _line;
    }

    //Конструктор копирования
    TException(const TException &e)
    {
        int n1 = strlen(e.file);
        file = new char[n1 + 1];
        strcpy(file, e.file);

        int n2 = strlen(e.func);
        func = new char[n2 + 1];
        strcpy(func, e.func);

        int n3 = strlen(e.desc);
        desc = new char[n3 + 1];
        strcpy(desc, e.desc);

        line = e.line;
    }

    //Печать исключения на экран
    //const, потому что никак не рискует изменить класс,
    //т.е. его можно вызывать и у const-объекта
    //const-метод внутри себя
    //может вызывать только другие константные методы
    void print() const
    {
        cout << "<<Исключение>>\n";
        cout << "Файл: " << file << '\n';
        cout << "Функция: " << func << '\n';
        cout << "Номер строки: " << line << '\n';
        cout << "Подробнее: " << desc << '\n';
    }

    //Вывод на экран в более понятном виде
    friend ostream &operator<<(ostream &os, const TException &e)
    {
        os << "<<Исключение>>\n";
        os << "Файл: " << e.file << '\n';
        os << "Функция: " << e.func << '\n';
        os << "Номер строки: " << e.line << '\n';
        os << "Подробнее: " << e.desc << '\n';
        return os;
    }

    //Деструктор
    ~TException()
    {
        delete[] file;
        delete[] func;
        delete[] desc;
    }
};

int main()
{
    setlocale(LC_ALL, "russian");
    TException e("File.txt", "func", 15, "Something");
    cout << e;
    return 0;
}