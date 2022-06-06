#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *prev, *next;
};

class CircularDoublyLL
{
private:
	Node *head;
public:
	CircularDoublyLL() {head = NULL;}
	CircularDoublyLL(int A[], int n);
	~CircularDoublyLL();

	void Display();
	void Insert(int pos, int x);
	int Delete(int pos);
	int Length();
	void Reverse();
};

CircularDoublyLL::CircularDoublyLL(int A[], int n)
{
	Node *new_node, *tail;
	head = new Node();
	head->data = A[0];
	head->prev = head->next = head;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		new_node = new Node;
		new_node->data = A[i];
		new_node->next = head;
		new_node->prev = tail;
		head->prev = new_node;
		tail->next = new_node;
		tail = new_node;
	}
}

void CircularDoublyLL::Insert(int pos, int x)
{
	Node *p = head;
	Node *t = new Node;
	t->data = x;

	if (pos < 0 || pos > Length())
		return;
	if (pos == 0)
	{
		t->next = head;
		t->prev = head->prev;
		t->prev->next = t;
		head->prev = t;
		head = t;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			p = p->next;
		t->next = p->next;
		t->prev = p;
		p->next->prev = t;
		p->next = t;
	}
}

CircularDoublyLL::~CircularDoublyLL()
{
	Node *p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

int CircularDoublyLL::Delete(int pos)
{
	Node *p = head;
	int x = -1;
	if (pos < 1 || pos > Length())
		return -1;
	if (pos == 1)
	{
		x = head->data;
		head = head->next;
		head->prev = head->prev->prev;
		head->prev->next = head;
		delete p;
		return x;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			p = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		x = p->data;
		delete p;
		return x;
	}
}

void CircularDoublyLL::Reverse()
{
	Node *q = NULL, *p = head;
	do
	{
		q = p;
		p = p->next;
		q->next = q->prev;
		q->prev = p;
	} while (p != head);
	head = q;
}

void CircularDoublyLL::Display()
{
	Node *p = head;
	do
	{
		cout << p->data << " ";
		p = p->next;
	} while (p != head);
	cout << endl;
}

int CircularDoublyLL::Length()
{
	int len = 0;
	Node *p = head;
	do
	{
		len++;
		p = p->next;
	} while (p != head);
	return len;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {5, 10, 15, 20, 25};
	CircularDoublyLL C(A, 5);
	C.Display();
	cout << "Deleted element: " << C.Delete(5) << endl;
	C.Display();
	cout << "No. of elements in LL: " << C.Length() << endl;;
	C.Insert(3, 32);
	C.Display();

	cout << "Reversed Linked list: ";
	C.Reverse();
	C.Display();

	return 0;
}