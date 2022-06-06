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

void Display(Node *p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

void RDisplay(Node *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		RDisplay(p->next);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {3, 5, 7, 10, 15};
	create(A, 5);
	Display(head);
	// RDisplay(head);
	return 0;
}