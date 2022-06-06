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

bool isLoop(Node *p)
{
	Node *q = p;
	while ((p && q) || p != q)
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : NULL;
	}
	if (p == q)
		return true;
	else
		return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *t1, *t2;
	int A[] = {5, 13, 9, 25, 1};
	create(A, 5);

	// to create a loop in LL
	t1 = head->next->next;
	t2 = head->next->next->next->next;
	t2->next = t1;

	if (isLoop(head))
		cout << "loop present";
	else
		cout << "No loop";
	return 0;
}