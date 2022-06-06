#include<iostream>
using namespace std;

class Node
{
public:
	char data;
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
	char pop();
	char peek(int index);
	char stackTop();
	bool isFull();
	bool isEmpty();
	bool isBalanced(string exp);
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

char Stack::pop()
{
	char x = -1;
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

char Stack::peek(int index)
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

char Stack::stackTop()
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

bool Stack::isBalanced(string exp)
{
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
			push(exp[i]);
		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if (isEmpty())
				return false;

			int x = pop();
			if (exp[i] == '}' && x != '{')
				return false;
			else if (exp[i] == ']' && x != '[')
				return false;
			else if (exp[i] == ')' && x != '(')
				return false;
		}
	}

	return isEmpty();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack st;
	string exp = "{([a+b]*[c-d)/e}";

	if (st.isBalanced(exp))
		cout << "Exp. balanced" << endl;
	else
		cout << "Exp. not balanced" << endl;

	return 0;
}