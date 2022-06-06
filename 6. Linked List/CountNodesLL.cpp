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

int RCount(Node *p)
{
	if (p == NULL)
		return 0;
	return RCount(p->next) + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {3, 5, 7, 10, 15};
	create(A, 5);
	cout << "No. of nodes: " << count(head);
	// cout << "No. of nodes: " << RCount(head);
	return 0;
}