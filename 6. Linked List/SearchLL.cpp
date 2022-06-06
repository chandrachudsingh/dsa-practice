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

// Node* LSearch(Node *p, int key)		//Linear Search
// {
// 	while (p != NULL)
// 	{
// 		if (key == p->data)
// 			return p;
// 		p = p->next;
// 	}
// }

Node* RLSearch(Node *p, int key)		// recursive linear
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return RLSearch(p->next, key);
}

void Display(Node *p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

// Improving Searching
// Using Move to Head
Node* LSearch(Node *p, int key)		//Linary Search with Move to Head
{
	Node *q = NULL;
	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = head;
			head = p;
			return p;
		}
		q = p;
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

	Node *temp = LSearch(head, 25);
	if (temp)
		cout << "Key is found: " << temp->data << endl;
	else
		cout << "Key not found" << endl;
	Display(head);

	return 0;
}