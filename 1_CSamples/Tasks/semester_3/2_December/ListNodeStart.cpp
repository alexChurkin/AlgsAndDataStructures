#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

/*
1. Звено списка. Работа со звеньями
   Список будет идентифицироваться по
   указателю на начало (первый элемент)
*/
struct TNode
{
    //Текущее значение
    int Value;
    //Указатель на следующее звено списка
    TNode *pNext;
};

int CountNodes(TNode *firstNode)
{
    TNode *node = firstNode;
    int result = 0;

    while (node != nullptr)
    {
        node = node->pNext;
        result++;
    }
    return result;
}

void AddNewNode(TNode *firstNode, int _value)
{
    TNode *node = firstNode;

    //После этого цикла в node будет последний элемент списка
    while (node->pNext != nullptr)
        node = node->pNext;

    //Создадим новый узел.
    //(Используем new, иначе узел исчезнет после функции)
    TNode *t = new TNode;
    t->Value = _value;
    t->pNext = nullptr;

    //Присвоим старому последнему звену новое последнее
    node->pNext = t;
}

//Удаление звена (любого, кроме первого)
//Для первого звена нужно предусмотреть отдельно
//(у него нет предыдущего)
void DeleteNodeWithValue(TNode *firstNode, int _value)
{
    TNode *prev = nullptr;
    TNode *node = firstNode;

    while (node->Value != _value)
    {
        prev = node;
        node = node->pNext;
    }

    prev->pNext = node->pNext;
    delete node;
}

int main()
{
    setlocale(LC_ALL, "russian");

    return 0;
}