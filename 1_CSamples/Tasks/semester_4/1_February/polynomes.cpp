#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

/*
Работа с полиномами. Начало.
*/

template <class T>
struct TNode
{
    T value;
    T *pNext;
};

template <class T>
class TList
{
protected:
    TNode *pFirst;
    //для добавления эл-та в список (в середину) нужно рассм. [pPrev] -> [pCur] -> []
    TNode *pCur, pPrev;
    TNode *pLast;
    //pStop в списке будет равен указателю на голову, чтобы не иметь
    //проблем при переходе от лин. списка к кольцевому
    TNode *pStop;
    //Длина списка
    int length;

public:
    //TODO Конструктор (здесь pStop = null; остальные указатели равны pStop; length = 0)
    //TODO IsEmpty: индикатором пустоты может быть length, или же то, что pFirst == pStop
    //TODO Добавить в начало, добавить в конец, добавить в текущую позицию
    //TODO Деструктор (многократное удаление первого звена)

    template <class T>
    void TList<T>::InsFirst(T element)
    {
        TNode<T> *newNode = new TNode<T>();
        newNode->value = element;
        newNode->pNext = pFirst;
        pFirst = newNode;
        length++;
        if (length == 1)
            pLast = pFirst;
    }

    template <class T>
    void TList<T>::InsLast(T element)
    {
        if (length > 0)
        {
            TNode<T> *newNode = new TNode<T>();
            newNode->value = element;
            newNode->pNext = pStop;

            pLast->pNext = newNode;
            pLast = newNode;
        }
        else
        {
            InsFirst(element);
        }

        length++;
    }

    //Добавляет новый элемент перед текущим
    template <class T>
    void TList<T>::InsCur(T element)
    {
        

        length++;
    }

    //TODO DelFirst (удаление первого)
    //TODO DelCurrent (удаление текущего, и текущим становится следующий за ним)
    //А далее уже говорим про кольцевой список
};

struct TMonom
{
    //Коэффициент
    double coeff;
    //Степени при x, y и z
    int x, y, z;

    TMonom()
    {
        coeff = 0;
        x = y = z = 0;
    }

    bool operator==(const TMonom &monom)
    {
        return (x == monom.x && y == monom.y && z == monom.z);
    }

    bool operator<(const TMonom &monom)
    {
        //TODO if(x <= monom.x) return false;
    }

    //TODO Ввод-вывод для удобства в будущем
};

int main()
{
    setlocale(LC_ALL, "russian");
    
    return 0;
}