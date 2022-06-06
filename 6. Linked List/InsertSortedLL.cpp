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

void InsertSorted(Node *p, int x)
{
	Node *new_node = new Node();
	new_node->data = x;

	if (head == NULL || p->data >= new_node->data)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		while (p->next != NULL && p->next->data < new_node->data)
			p = p->next;
		new_node->next = p->next;
		p->next = new_node;
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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {3, 9, 12, 15, 20};
	create(A, 5);
	InsertSorted(head, 18);
	InsertSorted(head, 5);
	InsertSorted(head, 24);
	InsertSorted(head, 1);
	Display(head);
	return 0;
}