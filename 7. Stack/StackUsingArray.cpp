#include<iostream>
using namespace std;

class Stack
{
private:
	int size, top;
	int *s;

public:
	Stack();
	Stack(int size);

	void Display();
	void push(int x);
	int pop();
	int peek(int index);
	int stackTop();
	bool isFull();
	bool isEmpty();
};

Stack::Stack()
{
	cout << "Enter size: ";
	cin >> size;
	top = -1;
	s = new int[size];
}

Stack::Stack(int size)
{
	this->size = size;
	top = -1;
	s = new int[size];
}

void Stack::Display()
{
	for (int i = top; i >= 0; i--)
		cout << s[i] << " ";
	cout << endl;
}

void Stack::push(int x)
{
	if (top == size - 1)
	{
		cout << "Stack overflow!";
		return;
	}
	s[++top] = x;
}

int Stack::pop()
{
	if (top == -1)
	{
		cout << "Stack underflow!";
		return -1;
	}
	return s[top--];
}

int Stack::peek(int index)
{
	if (index - 1 > top)
	{
		cout << "Invalid Index";
		return -1;
	}
	return s[index - 1];
}

int Stack::stackTop()
{
	if (isEmpty())
	{
		cout << "Stack empty!";
		return -1;
	}
	return s[top];
}

bool Stack::isFull()
{
	return top == size - 1;
}

bool Stack::isEmpty()
{
	return top == -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack st;
	st.push(2);
	st.push(4);
	st.push(6);
	st.push(8);
	st.push(10);
	st.Display();

	cout << "Popped element: " << st.pop() << endl;
	cout << "Topmost element: " << st.stackTop() << endl;
	cout << "2nd element: " << st.peek(2) << endl;

	st.push(100);
	if (st.isFull())
		cout << "Stack Full" << endl;
	else
		cout << "Stack Not Full" << endl;

	if (st.isEmpty())
		cout << "Stack Empty" << endl;
	else
		cout << "Stack not Empty" << endl;

	return 0;
}