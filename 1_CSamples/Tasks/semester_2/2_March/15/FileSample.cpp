#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    //Запись в файл
    ofstream ofs;
    ofs.open("goout.txt");
    //Запись в конец
    //ofs.open("goout.txt", ios::opp);
    ofs << "Вывод в файл!!! :)))";
    ofs.close();

    /*
    //Чтение файла
    int somevar;

    ifstream ifs;
    ifs.open("goout.txt");
    ifs >> somevar;
    ifs.close();
    */
    return 0;
}