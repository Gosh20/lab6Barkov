#pragma once
#include <iostream>
#include "AbstractStack.h"
using namespace std;

template<typename T>
class StackArr: public AbstractStack<T>
{
	T *arr;
	int count;
	int end = 0, start = 0, size = 0;

public:

	StackArr(int count)
		: count(count)
	{
		this->count = count;
		arr = new T[count];
	}

	StackArr(const StackArr &other)
	{
		arr = new T[other.count];
		count = other.count;
		end = other.end;
		start = other.start;
		size = other.size;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}


	StackArr(StackArr &&other)
	{
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}

	~StackArr()
	{
		delete[] arr;
	}

	StackArr&operator=(const StackArr &other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = new T[other.count];
		count = other.count;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}

	StackArr&operator=(StackArr &&other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}

	int GetSize()
	{
		return this->size;
	}

	void Push(T element)
	{
		if (size <= count)
		{
			arr[end] = element;
			end = (end + 1);
			size++;
		}
	}

	T Pop()
	{
		if (size > 0)
		{
			T element = arr[start];
			start = (start + 1) % count;
			size--;
			return element;
		}
		return 0;
	}

	T Peek()
	{
		return arr[start];
	}

	bool CheckNoEmptyStack()
	{
		return (size > 0);
	}

	friend ostream& operator<<(ostream& stream, StackArr& a)
	{
		for (int i = 0; i <= a.count; ++i)
			cout << a.arr[i] << " ";
		return stream;
	}
};