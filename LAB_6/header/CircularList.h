#pragma once

#include "Node.h"

template<typename T>

class CircularList

{
	Node<T> *head;
	
public:
	int size = 0;
	CircularList(); //инициализация
	CircularList(const CircularList &other); //копирование
	CircularList(CircularList &&other); //перемещение
	CircularList &operator=(const CircularList &other); //присваивание
	CircularList &operator=(CircularList &&other); //присваивание с еремещением
	~CircularList(); //деструктор
	int GetSize();
	Node<T> *Find(int number);
	void Push(T element, int number); //Вставка (добавление) элемента
	T Remove(int number); //Удаление (взятие) элемента
	T Peek(int number); //Просмотр (взятие без удаления) элемента
	bool CheckNoEmptyList(); //Проверка наличия элементов
	friend ostream & operator <<(ostream & stream, const CircularList<T> &a); //Вывод
};

template<typename T>
CircularList<T>::CircularList()
	: head(NULL)
{
	head = new Node<T>;
	Node<T> *node = new Node<T>;
	head->next = node;
	head->previous = node;
	node->next = head;
	node->previous = head;
}

template<typename T>
CircularList<T>::~CircularList() //деструктор
{
	Node<T> *node = head;
	while (node->next != head)
	{
		node = node->next;
		delete node->previous;
	}
	delete head;
}

template<typename T>
CircularList<T>::CircularList(const CircularList &other) //конструктор копирования
{
	Node<T> oldOldNode = other.head;
	head = other.head;
	Node<T> newOldNode = head;
	size = other.size;
	while (oldNode->next != other.head)
	{
		Node<T> *newNewNode;
		newOldNode->next = newNewNode;
		newNewNode->previous = newOldist;
		newOldNode = newOldNode->next;
		newOldNode->data = oldOldNode->data;
	}
	newOldNode->next = head;
	head->previous = newOldNode;
}

template<typename T>
CircularList<T>::CircularList(CircularList &&other) //перемещение
{
	head = other.head;
	size = other.size;
	other.head = nullptr;
}

template<typename T>
CircularList<T> &CircularList<T>::operator=(const CircularList &other) //присваивание
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = new Node<T>;
	Node<T> *node = head;
	while (node->next != head)
	{
		Node<T> *newNode = new Node<T>;
		Node<T> *oldNode = node->next;
		node->next = newNode;
		newNode->previous = node;
		newNode->data = oldNode->data;
	}
}

template<typename T>
CircularList<T> &CircularList<T>::operator=(CircularList &&other) //присваивание с перемещением
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = other.head;
	other.head = nullptr;
}

template<typename T>
int CircularList<T>::GetSize()
{
	return this->size;
}

template<typename T>
Node<T> *CircularList<T>::Find(int number)
{
	Node<T> *node = head->next;
	for (int i = 0; i < number; i++)
	{
		node = node->next;
	}
	return node;
}

template<typename T>
void CircularList<T>::Push(T element, int number) //Вставка (добавление) элемента
{
	Node<T> *previousNode = this->Find(number);
	Node<T> *nextNode = previousNode->next;
	Node<T> *newNode = new Node<T>;
	newNode->data = element;
	previousNode->next = newNode;
	newNode->previous = previousNode;
	newNode->next = nextNode;
	nextNode->previous = newNode;
	size++;
}

template<typename T>
T CircularList<T>::Remove(int number) //Удаление (взятие) элемента
{
	if (size > 0)
	{
		Node<T> *oldNode = this->Find(number);
		Node<T> *nextNode = oldNode->next;
		Node<T> *previousNode = oldNode->previous;
		T element = oldNode->data;
		nextNode->previous = previousNode;
		previousNode->next = nextNode;
		delete oldNode;
		size--;
		return element;
	}
	return 0;
}

template<typename T>
T CircularList<T>::Peek(int number) //Просмотр (взятие без удаления) элемента
{
	Node<T> *node = this->Find(number);
	return node->data;
}

template<typename T>
bool CircularList<T>::CheckNoEmptyList() //Проверка наличия элементов
{
	return (size > 0);
}

template<typename T>
ostream & operator << (ostream & stream, const CircularList<T> &a) //Вывод
{
	CircularList<T> b = a;
	stream << "=====\n";
	for (int i = 0; i < b.size; i++)
	{
		stream << "| " << b.Remove() << "\n";
	}
	stream << "=====\n";
	return stream;
}