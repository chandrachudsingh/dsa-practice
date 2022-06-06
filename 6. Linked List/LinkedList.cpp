#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *head;
public:
	LinkedList() {head = NULL;}
	LinkedList(int A[], int n);
	~LinkedList();

	void Display();
	void Insert(int pos, int x);
	int Delete(int pos);
	int count();
};

LinkedList::LinkedList(int A[], int n)
{
	Node *new_node, *tail;
	head = new Node();
	head->data = A[0];
	head->next = NULL;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		new_node = new Node();
		new_node->data = A[i];
		new_node->next = NULL;
		tail->next = new_node;
		tail = new_node;
	}
}

void LinkedList::Insert(int pos, int x)
{
	Node *p = head;
	Node *t = new Node();
	t->data = x;

	if (pos < 0 || pos > count())
		return;
	if (pos == 0)
	{
		t->next = head;
		head = t;
	}
	else if (pos > 0)
	{
		for (int i = 0; i < pos - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

LinkedList::~LinkedList()
{
	Node *p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

int LinkedList::Delete(int pos)
{
	Node *q, *p = head;
	int x = -1;
	if (pos < 1 || pos > count())
		return -1;
	if (pos == 1)
	{
		q = head;
		x = head->data;
		head = head->next;
		delete q;
		return x;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}

void LinkedList::Display()
{
	Node *p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int LinkedList::count()
{
	int c = 0;
	Node *p = head;
	while (p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {5, 13, 9, 25, 1};
	LinkedList l(A, 5);
	l.Display();
	cout << "Deleted element: " << l.Delete(3) << endl;
	l.Display();
	cout << "No. of elements in LL: " << l.count() << endl;;
	l.Insert(3, 32);
	l.Display();

	return 0;
}