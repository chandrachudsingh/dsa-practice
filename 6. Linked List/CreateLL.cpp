#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
}*head = NULL;

// Creating a LL by Inserting at last
void InsertLast(int x)
{
	Node *new_node, *tail;
	new_node = new Node();
	new_node->data = x;
	new_node->next = NULL;
	if (head == NULL)
		head = tail = new_node;
	else
	{
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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	InsertLast(5);
	InsertLast(12);
	InsertLast(9);
	InsertLast(25);
	InsertLast(2);
	Display(head);
	return 0;
}