#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *head;
public:
	LinkedList() {head = NULL;}
	LinkedList(int A[], int n);
	~LinkedList();

	void Display();
	void FindMidNode();
};

LinkedList::LinkedList(int A[], int n)
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

LinkedList::~LinkedList()
{
	Node *p = head;
	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

void LinkedList::Display()
{
	Node *p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

// Middle node can be found by 2 ways:
// 1. calculate length and traverse to mid element - TIME(N)
// 2. using 2 pointers - TIME(N/2) -->(Preferred)
// 3. Using stack and finding its size.
/* Using 2 pointers - we take 2 pointers with one moving single node
 at a time while other moving 2 nodes at a time. So when the 2nd pointer
 reaches the end node the 1st pointer reached the middle node.
*/
void LinkedList::FindMidNode()
{
	Node *p, *q;
	p = q = head;
	while (q)
	{
		q = q->next;
		if (q)
			q = q->next;
		if (q)
			p = p->next;
	}
	cout << p->data << " is the middle element.";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {5, 13, 9, 25, 1, 45};
	LinkedList l(A, 6);
	l.Display();
	l.FindMidNode();

	return 0;
}