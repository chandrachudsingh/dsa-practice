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
	void FindIntersection();
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

// Using stack
void LinkedList::FindIntersection()
{
	Node *p = first;
	while (p)
		Push(&stk1, p);
	p = second;
	while (p)
		Push(&stk2, p);
	while (stackTop(stk1) == stackTop(stk2))
	{
		p = Pop(&stk1);
		Pop(&stk2);
	}
	cout << "First common element: " << p->data;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {5, 13, 9, 25, 1, 45};
	LinkedList l(A, 6);
	l.Display();
	l.FindIntersection();

	return 0;
}