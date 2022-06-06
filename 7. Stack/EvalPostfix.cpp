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
	int precedence(char x);
	bool isOperand(char x);
	int EvalPostfix(string postfix);
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

int Stack::precedence(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	return 0;
}

bool Stack::isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return false;
	return true;
}

int Stack::EvalPostfix(string postfix)
{
	int x, y, r;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))
			push(postfix[i] - '0');
		else
		{
			y = pop();
			x = pop();
			switch (postfix[i])
			{
			case '+':
				r = x + y;
				break;
			case '-':
				r = x - y;
				break;
			case '*':
				r = x * y;
				break;
			case '/':
				r = x / y;
				break;
			}
			push(r);
		}
	}
	return pop();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack st;
	string postfix = "234*+82/-";
	cout << "Result of expression is: " << st.EvalPostfix(postfix);

	return 0;
}