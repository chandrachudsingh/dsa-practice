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
	int precedence(char x);
	bool isOperand(char x);
	string InfixToPostfix(string infix);
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

string Stack::InfixToPostfix(string infix)
{
	int i = 0, j = 0;
	string postfix;

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (precedence(infix[i]) > precedence(top->data))
				push(infix[i++]);
			else
				postfix[j++] = pop();
		}
	}
	while (top != NULL)
		postfix[j++] = pop();
	postfix[j] = '\0';
	return postfix;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack st;
	st.push('#');
	string infix = "a+b*c-d/e";
	string postfix = st.InfixToPostfix(infix);
	int i = 0;
	while (postfix[i] != '\0')
		cout << postfix[i++];

	return 0;
}