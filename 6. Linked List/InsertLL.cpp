#include<iostream>
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

int count(Node *p)
{
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}

void Insert(Node *p, int pos, int x)
{
	Node *t = new Node();
	t->data = x;

	if (pos < 0 || pos > count(p))
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

void Display(Node *p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {3, 5, 37, 25, 10, 9};
	create(A, 6);
	Insert(head, 5, 12);
	Display(head);
	return 0;
}