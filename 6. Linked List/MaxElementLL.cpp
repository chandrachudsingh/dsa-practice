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

int Max(Node *p)
{
	// initialize max as INT_MIN by climits library
	int max = INT_MIN;
	while (p != NULL)
	{
		if (max < p->data)
			max = p->data;
		p = p->next;
	}
	return max;
}

int RMax(Node *p)
{
	int x = 0;
	if (p == NULL)
		return INT_MIN;
	x = RMax(p->next);
	return x > p->data ? x : p->data;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {3, 5, 37, 15, 10, 9};
	create(A, 5);
	cout << "Max of Elements: " << Max(head);
	// cout << "Max of Elements: " << RMax(head);
	return 0;
}