#ifndef STACK_H
#define STACK_H

#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	int size, top;
	T *s;

public:
	Stack();
	Stack(int size);

	void Display();
	void push(T x);
	T pop();
	T stackTop();
	bool isFull();
	bool isEmpty();
};

template<class T>
Stack<T>::Stack()
{
	cout << "Enter size: ";
	cin >> size;
	top = -1;
	s = new T[size];
}

template<class T>
Stack<T>::Stack(int size)
{
	this->size = size;
	top = -1;
	s = new T[size];
}

template<class T>
void Stack<T>::Display()
{
	for (int i = top; i >= 0; i--)
		cout << s[i] << " ";
	cout << endl;
}

template<class T>
void Stack<T>::push(T x)
{
	if (top == size - 1)
	{
		cout << "Stack overflow!";
		return;
	}
	s[++top] = x;
}

template<class T>
T Stack<T>::pop()
{
	if (top == -1)
		cout << "Stack underflow!";
	else
		return s[top--];
}

template<class T>
T Stack<T>::stackTop()
{
	if (isEmpty())
	{
		cout << "Stack empty!";
		return NULL;
	}
	return s[top];
}

template<class T>
bool Stack<T>::isFull()
{
	return top == size - 1;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return top == -1;
}

#endif
