#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *prev, *next;
};

class DoublyLL
{
private:
	Node *head;
public:
	DoublyLL() {head = NULL;}
	DoublyLL(int A[], int n);
	~DoublyLL();

	void Display();
	void Insert(int pos, int x);
	int Delete(int pos);
	int Length();
	void Reverse();
};

DoublyLL::DoublyLL(int A[], int n)
{
	Node *new_node, *tail;
	head = new Node();
	head->data = A[0];
	head->prev = head->next = NULL;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		new_node = new Node;
		new_node->data = A[i];
		new_node->next = NULL;
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}
}

void DoublyLL::Insert(int pos, int x)
{
	Node *p = head;
	Node *t = new Node();
	t->data = x;

	if (pos < 0 || pos > Length())
		return;
	if (pos == 0)
	{
		t->next = head;
		t->prev = NULL;
		head->prev = t;
		head = t;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			p = p->next;
		t->next = p->next;
		t->prev = p;
		if (p->next)
			p->next->prev = t;
		p->next = t;
	}
}

DoublyLL::~DoublyLL()
{
	Node *p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

int DoublyLL::Delete(int pos)
{
	Node *p = head;
	int x = -1;
	if (pos < 1 || pos > Length())
		return -1;
	if (pos == 1)
	{
		x = head->data;
		head = head->next;
		if (head)
			head->prev = NULL;
		delete p;
		return x;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			p = p->next;
		p->prev->next = p->next;
		if (p->next)
			p->next->prev = p->prev;
		x = p->data;
		delete p;
		return x;
	}
}

void DoublyLL::Reverse()
{
	Node *q = NULL, *p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = q->prev;
		q->prev = p;
	}
	head = q;
}

void DoublyLL::Display()
{
	Node *p = head;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int DoublyLL::Length()
{
	int len = 0;
	Node *p = head;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {5, 10, 15, 20, 25};
	DoublyLL D(A, 5);
	D.Display();
	cout << "Deleted element: " << D.Delete(5) << endl;
	D.Display();
	cout << "No. of elements in LL: " << D.Length() << endl;;
	D.Insert(3, 32);
	D.Display();

	D.Reverse();
	D.Display();

	return 0;
}