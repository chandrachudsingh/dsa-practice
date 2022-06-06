#include<iostream>
#include<climits>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
	Node *new_node, *tail;
	first = new Node();
	first->data = A[0];
	first->next = NULL;
	tail = first;

	for (int i = 1; i < n; i++)
	{
		new_node = new Node();
		new_node->data = A[i];
		new_node->next = NULL;
		tail->next = new_node;
		tail = new_node;
	}
}

void create2(int A[], int n)
{
	Node *new_node, *tail;
	second = new Node();
	second->data = A[0];
	second->next = NULL;
	tail = second;

	for (int i = 1; i < n; i++)
	{
		new_node = new Node();
		new_node->data = A[i];
		new_node->next = NULL;
		tail->next = new_node;
		tail = new_node;
	}
}

void Display(Node * p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

void Concat(Node *p, Node *q)
{
	third = p;
	while (p->next != NULL)
		p = p->next;
	p->next = q;
}

void Merge(Node *p, Node *q)
{
	Node *last;
	if (p->data <= q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}

	while (p && q)
	{
		if (p->data <= q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if (p)
		last->next = p;
	if (q)
		last->next = q;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {10, 20, 30, 40, 50};
	create(A, 5);
	int B[] = {15, 20, 25, 45, 45};
	create2(B, 5);
	// Concat(first, second);
	// cout << "Concatenated linked list: ";

	Merge(first, second);
	cout << "Merged linked list: ";
	Display(third);
	return 0;
}