#pragma once


template <typename T>
class AbstractStack
{
public:

	virtual void Push(T element) = 0; 
	virtual T Pop() = 0;
	virtual T Peek() = 0; 
	virtual bool CheckNoEmptyStack() = 0;
};