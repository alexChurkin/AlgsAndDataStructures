#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;



/* TSTack begin............................................. */
template <class T>
class TStack
{
private:
	//Ïðîñòî ìàññèâ
	T* arr;
	int size;
	//Íîìåð ïîñëåäíåãî ýëåìåíòà ñòåêà
	int pos;

public:
	TStack(int _size = 300);
	TStack(const TStack& other);
	~TStack();

	TStack& operator=(const TStack& other);

	//Ñðàâíåíèå äâóõ ñòåêîâ
	bool operator==(const TStack& other) const;
	bool operator!=(const TStack& other) const;

	bool IsEmpty() const;
	bool IsNotEmpty() const;
	bool IsFull() const;
	bool IsNotFull() const;

	void Push(T item);
	T Pop();

	void Clear();

	T Top() const;

	friend std::ostream& operator<<(std::ostream& out, const TStack& v)
	{
		for (int i = 0; i <= v.pos; i++)
			out << v.arr[i] << ' ';
		return out;
	}
};

template <class T>
TStack<T>::TStack(int _size)
{
	if (_size <= 0)
		throw _size;

	size = _size;
	arr = new T[size];
	pos = -1;
}

template <class T>
TStack<T>::~TStack()
{
	delete[] arr;
}

template <class T>
TStack<T>::TStack(const TStack& other)
{
	size = other.size;
	pos = other.pos;

	arr = new T[size];

	for (int i = 0; i <= pos; i++)
		arr[i] = other.arr[i];
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack& other)
{
	if (size != other.size)
	{
		delete[] arr;
		size = other.size;
		arr = new T[size];
	}

	pos = other.pos;

	for (int i = 0; i <= pos; i++)
		arr[i] = other.arr[i];

	return *this;
}

template <class T>
bool TStack<T>::operator==(const TStack& other) const
{
	if (size != other.size)
		return false;

	for (int i = 0; i < size; i++)
		if (arr[i] != other.arr[i])
			return false;

	return true;
}

template <class T>
bool TStack<T>::operator!=(const TStack& other) const
{
	return !operator==(other);
}

template <class T>
bool TStack<T>::IsEmpty() const
{
	return (pos == -1);
}

template <class T>
bool TStack<T>::IsNotEmpty() const
{
	return (pos != -1);
}

template <class T>
bool TStack<T>::IsFull() const
{
	return (pos == (size - 1));
}

template <class T>
bool TStack<T>::IsNotFull() const
{
	return (pos < (size - 1));
}

template <class T>
void TStack<T>::Push(T item)
{
	if (IsFull())
		throw "Can't push: Stack is already full";

	pos++;
	arr[pos] = item;
}

template <class T>
T TStack<T>::Pop()
{
	if (IsEmpty())
		throw "Can't Pop: Stack is empty";

	T item = arr[pos];
	pos--;

	return item;
}

template <class T>
void TStack<T>::Clear()
{
	pos = -1;
}

template <class T>
T TStack<T>::Top() const
{
	if (IsEmpty())
		throw "Can't access top element: Stack is empty";

	return arr[pos];
}
/* TSTack end............................................. */





//Звено иерархического списка (текста)
struct TNode
{
    char str[81];
    TNode *pNext;
    TNode *pDown;
    //                     +
    //                    +++
    //                   +++++
    //зачем нам puвлик (((-_-)))
    //                    ---
    //                  -------
    //              >>|||-----|||<<
    //                    ---
    //                  --   --
    //                  ---  ---
    //                  -----  -----
    TNode(char *_str = nullptr,
          TNode *_pNext = nullptr,
          TNode *_pDown = nullptr)
    {
        if (_str == nullptr)
            str[0] = '\0';
        else
            strcpy(str, _str);
        pNext = _pNext;
        pDown = _pDown;
    }

    ~TNode()
    {
        //
    }
};

//Иерархический текст
class TText
{
private:
    TNode *pFirst, *pCurr;
    //В стеке хранятся все указатели, до текущего (текущий не хранится)
    //При перемещениях стек модифицируем
    TStack<TNode *> st;

    //Чтение из файла, вывод на экран
    //Предполагаем, что в файле текст записан так:
    //вложенность регулируется {}
    //файл без вложенностей - последовательность строк
    //строка1
    //строка2
    //.......
    //строкаn

    //Пока не конец файла (while != EOF), читаем новую строку и пристыковываем через pNext
    //отступов никаких нет, текст без пробелов в начале.
    //затем началась подчинённая часть
    //скобки находятся в первом символе строки (в строках не может быть скобок)

    //строка1
    //строка2
    //{
    //  строка21
    //  строка21
    //  {
    //  строка211
    //  }
    //}
    //строкаn

    ///(отступов нет)

    //while != EOF {
    //если видим открывающую скобку, вызываем такую же функцию
    //в качестве результата указатель на верхнюю строку
    //}
    //Рекурсивное чтение из файла
    TNode *ReadRec(ifstream &fin)
    {
        TNode *pTemp = nullptr, *pHead = nullptr;
        char str[81];

        while (!fin.eof())
        {
            fin.getline(str, 81, '\n');
            if (str[0] == '{')
                pTemp->pDown = ReadRec(fin);
            else if (str[0] == '}')
                break;
            else
            {
                TNode *newNode = new TNode(str);
                if (pHead == nullptr)
                    pTemp = pHead = newNode;
                else
                    pTemp->pNext = newNode;
                pTemp = newNode;
            }
        }
        return pHead;
    }

    //Печать на экран текста
    //напечатать саму строку, потом всё по pDown, потом всё на pNext
    //(то есть снова рекурсия)
    void PrintRec(TNode *p)
    {
        //можно ещё скобки печатать (если pDown существует, печатать скобки сверху, снизу)
        //можно даже смещение текста делать
        if (p)
        {
            cout << p->str << '\n';
            PrintRec(p->pDown);
            PrintRec(p->pNext);
        }
    }

public:
    //Перемещение указателя pCurr на следующее звено
    void GoNextNode()
    {
        if (pCurr == nullptr)
            throw "Can't reach the next node: current node doesn't exist";
        {
            st.Push(pCurr);
            pCurr = pCurr->pNext;
        }
    }
    //Перемещение указателя pCurr на звено подчинённой ему части
    void GoDownNode()
    {
        if (pCurr == nullptr)
            throw "Can't reach down node: current node doesn't exist";
        {
            st.Push(pCurr);
            pCurr = pCurr->pDown;
        }
    }

    //TODO GoUp (перейти назад по стеку через Pop())
    void GoUp()
    {
        if(st.IsEmpty())
            throw "Can't go up: top node doesn't exist";
    }

    //TODO GoFirstNode

    //Вставка новой строки за текущей
    void InsNextLine(char *_str)
    {
        if (pCurr == nullptr)
            throw "Can't insert next line: current node doesn't exist";
        TNode *newNode = new TNode(_str);
        newNode->pNext = pCurr->pNext;
        pCurr->pNext = newNode;
    }

    //Вставка нового заголовка за текущей строкой и
    //переподчинение всей нижней части списка ему
    void InsNextSection(char *_str)
    {
        if (pCurr == nullptr)
            throw "Can't insert next section: current node doesn't exist";
        TNode *newNode = new TNode(_str);
        newNode->pDown = pCurr->pNext;
        pCurr->pNext = newNode;
    }

    //Вставка новой строки в начало подчинённой части
    void InsDownLine(char *_str)
    {
        if (pCurr == nullptr)
            throw "Can't insert down line: current node doesn't exist";
        TNode *newNode = new TNode(_str);
        newNode->pNext = pCurr->pDown;
        pCurr->pDown = newNode;
    }

    //Вставка нового заголовка в подчинённую часть
    void InsDownSection(char *_str)
    {
        if (pCurr == nullptr)
            throw "Can't insert down section: current node doesn't exist";
        TNode *newNode = new TNode(_str);
        newNode->pDown = pCurr->pDown;
        pCurr->pDown = newNode;
    }

    //С утечкой памяти (удаляется только pDel, но не его другие указатели)!!!
    //Удалить следующее звено
    void DelNext()
    {
        if (pCurr == nullptr)
            throw "Can't delete next line/section: current node doesn't exist";
        TNode *pDel = pCurr->pNext;

        if (pDel == nullptr)
            throw "Nothing to delete: next line/section is nullptr";
        pCurr->pNext = pDel->pNext;
        delete pDel;
    }

    void DelDown()
    {
        if (pCurr == nullptr)
            throw "Can't delete next line/section: current node doesn't exist";
        TNode *pDel = pCurr->pDown;

        if (pDel == nullptr)
            throw "Nothing to delete: next line/section is nullptr";
        pCurr->pDown = pDel->pNext;
        delete pDel;
    }

    //Загрузка текста из файла
    void Load(string s)
    {
        ifstream ifs(s);
        pFirst = ReadRec(ifs);
    }

    void Print()
    {
        PrintRec(pFirst);
    }
};

int main()
{
    setlocale(LC_ALL, "russian");

    return 0;
}