#pragma once
#include <iostream>
#include <string>

/* ................... TQueueException ................... */

class TQueueException
{
private:
	std::string desc;

public:
	TQueueException(std::string _desc)
	{
		desc = _desc;
	}
	TQueueException(const TQueueException& e)
	{
		desc = e.desc;
	}

	friend std::ostream& operator<<(std::ostream& os, const TQueueException& e)
	{
		os << "Exception message: " << e.desc << '\n';
		return os;
	}
};

/* ....................... TQueue ........................ */

template <class T>
class TQueue
{
private:
	T* arr;
	int MaxSize;
	int count;
	int head, tail;

public:
	TQueue(int _MaxSize = 100);
	TQueue(const TQueue<T>& other);
	~TQueue();
	TQueue<T>& operator=(const TQueue<T>& other);

	bool operator==(const TQueue<T>& other) const;
	bool operator!=(const TQueue<T>& other) const;

	int GetMaxSize();
	int GetCount();
	int GetHead();

	bool IsEmpty();
	bool IsNotEmpty();

	bool IsFull();
	bool IsNotFull();

	void Push(T element);
	T Pop();

	void Clear();

	friend std::ostream& operator<<(std::ostream& out, const TQueue& q)
	{
		out << "[ ";

		for (int tCount = q.count, i = q.head; tCount > 0; tCount--)
		{
			out << q.arr[i] << ' ';
			i = (++i) % q.MaxSize;
		}

		out << "]";

		return out;
	}
};


template <class T>
TQueue<T>::TQueue(int _MaxSize)
{
	if (_MaxSize <= 1) {
		throw TQueueException("Queue MaxSize cannot be < 2");
	}

	MaxSize = _MaxSize;
	arr = new T[MaxSize];

	count = 0;
	tail = -1, head = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& other)
{
	MaxSize = other.MaxSize;
	arr = new T[MaxSize];

	count = other.count;
	tail = other.tail, head = other.head;

	//Active part copying
	for (int tCount = count, i = head; tCount > 0; tCount--)
	{
		arr[i] = other.arr[i];
		i = (++i) % MaxSize;
	}
}

template <class T>
TQueue<T>::~TQueue()
{
	delete[] arr;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& other)
{
	if (this == &other)
		return *this;

	if (MaxSize != other.MaxSize) {
		MaxSize = other.MaxSize;
		delete[] arr;
		arr = new T[MaxSize];
	}
	count = other.count;
	tail = other.tail, head = other.head;

	//Active part copying
	for (int tCount = count, i = head; tCount > 0; tCount--)
	{
		arr[i] = other.arr[i];
		i = (++i) % MaxSize;
	}

	return *this;
}

template <class T>
bool TQueue<T>::operator==(const TQueue<T>& other) const
{
	if (MaxSize != other.MaxSize) return false;
	if (count != other.count) return false;
	if (head != other.head) return false;
	if (tail != other.tail) return false;

	for (int tCount = count, i = head; tCount > 0; tCount--)
	{
		if (arr[i] != other.arr[i]) return false;
		i = (++i) % MaxSize;
	}

	return true;
}

template <class T>
bool TQueue<T>::operator!=(const TQueue<T>& other) const
{
	return !operator==(other);
}

template<class T>
int TQueue<T>::GetMaxSize()
{
	return MaxSize;
}

template<class T>
int TQueue<T>::GetCount()
{
	return count;
}

template<class T>
int TQueue<T>::GetHead()
{
	return head;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
	return (count == 0);
}

template <class T>
bool TQueue<T>::IsNotEmpty()
{
	return (count > 0);
}

template <class T>
bool TQueue<T>::IsFull()
{
	return (count == MaxSize);
}

template <class T>
bool TQueue<T>::IsNotFull()
{
	return (count < MaxSize);
}

template <class T>
void TQueue<T>::Push(T element)
{
	if (IsFull())
		throw TQueueException("Can't push to a full queue");

	tail = (++tail) % MaxSize;

	arr[tail] = element;

	count++;
}

template <class T>
T TQueue<T>::Pop()
{
	if (IsEmpty())
		throw TQueueException("Can't pop from an empty queue");

	T temp = arr[head];
	head = (++head) % MaxSize;

	count--;
	return temp;
}

template <class T>
void TQueue<T>::Clear()
{
	count = 0;
	tail = -1, head = 0;
}