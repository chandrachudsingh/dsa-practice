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

int Delete(Node *p, int pos)
{
	Node *q;
	int x = -1;
	if (pos < 1 || pos > count(p))
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
	cout << "Deleted element: " << Delete(head, 3) << endl;
	cout << "Deleted element: " << Delete(head, 1) << endl;
	Display(head);
	return 0;
}