#include<iostream>
#include<climits>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
}*head = NULL;

void create(int A[], int n)
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

void Display(Node * p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

// 2 ways:-
// Reversing elements
// Reversing links (preferred)
void Reverse(Node *p)
{
	Node *q = NULL, *r = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}

void RReverse(Node *p)
{
	if (p != NULL)
	{
		RReverse(p, p->next);
		p->next = q;
	}
	else
		head = q;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {10, 20, 30, 40, 50};
	create(A, 5);
	Reverse(head);
	// RReverse(NULL, head);
	Display(head);
	return 0;
}