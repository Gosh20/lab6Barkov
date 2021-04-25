#pragma once

#include "AbstractStack.h"

#include "CircularList.h"

template<typename T>

class StackCL : public AbstractStack<T>

{
	CircularList<T> *Stack;
	int count;
	int size = 0;
public:
	StackCL(int count)
		: Stack(), count(count) {}
	
	StackCL(const StackCL &other)
	{
		Stack = other.Stack;
		count = other.count;
	}

	StackCL(StackCL &&other)
	{
		Stack = other.Stack;
		count = other.count;
	}

	StackCL<T> &operator=(const StackCL &other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Stack = other.Stack;
	}

	StackCL<T> &operator=(StackCL &&other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Stack = other.Stack;
	}

	~StackCL();

	void Push(T element) override //Вставка (добавление) элемента
	{
		if (Stack->GetSize() < count)
		{
			Stack->Push(element, Stack->GetSize());
		}
	}

	T Pop() override //Удаление (взятие) элемента
	{
		return Stack->Remove(1);
	}

	T Peek() override //Просмотр (взятие без удаления) элемента
	{
		return Stack->Peek(1);
	}
	int GetSize() 
	{
		return this->size;
	}
	bool CheckNoEmptyStack() override //Проверка наличия элементов
	{
		return Stack->CheckNoEmptyList();
	}
	friend ostream & operator << (ostream & stream, const StackCL<T> &a) //Вывод
	{
		StackCL<T> b = a;
		stream << "=====\n";
		for (int i = 0; i < b.count; i++)
		{
			stream << "| " << b.Pop() << "\n";
		}
		stream << "=====\n";
		return stream;
	}
};

template<typename T>
StackCL<T>::~StackCL()
{
	delete Stack;
}

