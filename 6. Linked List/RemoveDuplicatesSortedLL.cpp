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

void RemoveDuplicate(Node *p)
{
	Node *q = p->next;
	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {10, 20, 20, 30, 40, 40, 40};
	create(A, 7);
	RemoveDuplicate(head);
	Display(head);
	return 0;
}