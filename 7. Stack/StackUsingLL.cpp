#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Stack
{
private:
	Node *top;

public:
	Stack() {top = NULL;}

	void Display();
	int Length();
	void push(int x);
	int pop();
	int peek(int index);
	int stackTop();
	bool isFull();
	bool isEmpty();
};

void Stack::Display()
{
	Node *p = top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int Stack::Length()
{
	int len = 0;
	Node *p = top;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void Stack::push(int x)
{
	Node *t = new Node;
	if (t == NULL)
	{
		cout << "Stack overflow!";
		return;
	}
	t->data = x;
	t->next = top;
	top = t;
}

int Stack::pop()
{
	int x = -1;
	if (top == NULL)
	{
		cout << "Stack underflow!";
		return x;
	}
	Node *p = top;
	top = top->next;
	x = p->data;
	delete p;
	return x;
}

int Stack::peek(int index)
{
	if (index > Length())
	{
		cout << "Invalid Index";
		return -1;
	}
	Node *p = top;
	for (int i = 1; i < index; i++)
		p = p->next;
	return p->data;
}

int Stack::stackTop()
{
	if (isEmpty())
	{
		cout << "Stack empty!";
		return -1;
	}
	return top->data;
}

bool Stack::isFull()
{
	Node *t = new Node;
	return t == NULL;
}

bool Stack::isEmpty()
{
	return top == NULL;
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

	if (st.isFull())
		cout << "Stack Full" << endl;
	else
		cout << "Stack Not Full" << endl;

	st.pop();
	st.pop();
	st.pop();
	st.pop();
	if (st.isEmpty())
		cout << "Stack Empty" << endl;
	else
		cout << "Stack not Empty" << endl;

	return 0;
}