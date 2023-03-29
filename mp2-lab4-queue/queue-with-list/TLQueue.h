#pragma once
#include <iostream>
#include <string>

/* TLQueueException - класс исключения для TLQueue */

class TLQueueException
{
private:
	std::string desc;

public:
	TLQueueException(std::string _desc)
	{
		desc = _desc;
	}
	TLQueueException(const TLQueueException& e)
	{
		desc = e.desc;
	}

	friend std::ostream& operator<<(std::ostream& os, const TLQueueException& e)
	{
		os << "Exception message: " << e.desc << '\n';
		return os;
	}
};

/* TNode - звено односвязного списка */

template <class T>
struct TNode
{
	T value;
	TNode* pNext;
};

/* Очередь на основе односвязного списка.
 *
 * Работает следующим образом:
 * pFirst               pLast
 * [ ] -> [ ] -> [ ] -> [ ]
 * head                 tail
*/

template <class T>
class TLQueue
{
private:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	int size;

public:
	TLQueue();
	TLQueue(const TLQueue& other);
	TLQueue<T>& operator=(const TLQueue<T>& other);
	~TLQueue();

	int GetSize() const;
	bool IsEmpty() const;
	bool IsNotEmpty() const;

	void Push(T element);
	T Pop();

	T GetFirst() const;
	T GetLast() const;

	bool operator==(const TLQueue<T>& other) const;
	bool operator!=(const TLQueue<T>& other) const;

	void Clear();

	friend std::ostream& operator<<(
		std::ostream& out, const TLQueue& q)
	{
		TNode<T>* node = q.pFirst;
		out << "[ ";
		while (node != nullptr)
		{
			out << node->value << ' ';
			node = node->pNext;
		}
		out << "]";
		return out;
	}

private:
	void CopyNodesFrom(const TLQueue<T>& other);
};

template <class T>
TLQueue<T>::TLQueue()
{
	pFirst = pLast = nullptr;
	size = 0;
}

template <class T>
TLQueue<T>::TLQueue(const TLQueue& other)
{
	pFirst = pLast = nullptr;
	size = other.size;

	CopyNodesFrom(other);
}

template <class T>
TLQueue<T>& TLQueue<T>::operator=(const TLQueue<T>& other)
{
	if (this == &other)
		return *this;

	Clear();
	CopyNodesFrom(other);
	size = other.size;
}

template <class T>
TLQueue<T>::~TLQueue()
{
	Clear();
}

template <class T>
int TLQueue<T>::GetSize() const
{
	return size;
}

template <class T>
bool TLQueue<T>::IsEmpty() const
{
	return pFirst == nullptr;
}

template <class T>
bool TLQueue<T>::IsNotEmpty() const
{
	return pFirst != nullptr;
}

template <class T>
void TLQueue<T>::Push(T element)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->value = element;
	newNode->pNext = nullptr;

	if (pLast != nullptr)
		pLast->pNext = newNode;
	else
		pFirst = newNode;
	pLast = newNode;
	size++;
}

template <class T>
T TLQueue<T>::Pop()
{
	if (IsEmpty()) 
		throw TLQueueException(
			"Can't pop from an empty queue");

	T value = pFirst->value;
	TNode<T>* oldFirst = pFirst;
	pFirst = oldFirst->pNext;
	delete oldFirst;

	if (pFirst == nullptr)
		pLast = nullptr;

	size--;
	return value;
}

template <class T>
T TLQueue<T>::GetFirst() const
{
	if (IsEmpty())
		throw TLQueueException(
			"Can't get first element of an empty queue");
	return pFirst->value;
}

template <class T>
T TLQueue<T>::GetLast() const
{
	if (IsEmpty())
		throw TLQueueException(
			"Can't get last element of an empty queue");
	return pLast->value;
}

template <class T>
bool TLQueue<T>::operator==(const TLQueue<T>& other) const
{
	TNode<T>* node = pFirst;
	TNode<T>* nodeOther = other.pFirst;

	//Сравнение элементов звеньев
	while (node != nullptr && nodeOther != nullptr)
	{
		if (node->value != nodeOther->value) return false;
		node = node->pNext;
		nodeOther = nodeOther->pNext;
	}

	//Если в очередях различное число элементов -
	//они не равны
	if (node != nullptr || nodeOther != nullptr)
		return false;

	return true;
}

template <class T>
bool TLQueue<T>::operator!=(const TLQueue<T>& other) const
{
	return !operator==(other);
}

template <class T>
void TLQueue<T>::Clear()
{
	TNode<T>* node;
	while (pFirst != nullptr)
	{
		node = pFirst;
		pFirst = pFirst->pNext;
		delete node;
	}
	pLast = nullptr;
}

/* Последовательное копирование звеньев,
   начиная с 1-го */
template <class T>
void TLQueue<T>::CopyNodesFrom(
	const TLQueue<T>& other
)
{
	if (other.IsNotEmpty())
	{
		TNode<T>* newNode;
		//Копирование первого звена
		newNode = new TNode<T>;
		newNode->value = other.pFirst->value;
		newNode->pNext = nullptr;
		pFirst = newNode;

		//Копирование остальных звеньев:

		//Предыдущее звено текущего списка
		TNode<T>* prevNewNode = newNode;

		//Звено "другого" списка
		TNode<T>* otherNode = other.pFirst->pNext;

		while (otherNode != nullptr)
		{
			newNode = new TNode<T>;
			newNode->value = otherNode->value;
			newNode->pNext = nullptr;

			prevNewNode->pNext = newNode;

			prevNewNode = newNode;
			otherNode = otherNode->pNext;
		}
		pLast = prevNewNode;
	}
}