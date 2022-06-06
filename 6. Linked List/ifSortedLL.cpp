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

bool ifSorted(Node *p)
{
	int x = INT_MIN;
	while (p != NULL)
	{
		if (p->data < x)
			return false;
		x = p->data;
		p = p->next;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {3, 9, 12, 15, 20};
	create(A, 5);
	if (ifSorted(head))
		cout << "Sorted";
	else
		cout << "Not Sorted";
	return 0;
}