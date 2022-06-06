#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class CircularLL
{
private:
	Node *head;
public:
	CircularLL() {head = NULL;}
	CircularLL(int A[], int n);
	~CircularLL();

	void Display();
	void Insert(int pos, int x);
	int Delete(int pos);
	int Length();
};

CircularLL::CircularLL(int A[], int n)
{
	Node *new_node, *tail;
	head = new Node();
	head->data = A[0];
	head->next = head;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		new_node = new Node();
		new_node->data = A[i];
		new_node->next = tail->next;
		tail->next = new_node;
		tail = new_node;
	}
}

CircularLL::~CircularLL()
{
	Node *p = head, *q = head;
	while (head != q)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

int CircularLL::Length()
{
	Node *p = head;
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != head);
	return len;
}

void CircularLL::Insert(int pos, int x)
{
	Node *p, *new_node;

	if (pos < 0 || pos > Length())
		return;
	new_node = new Node;
	new_node->data = x;
	if (pos == 0)
	{
		if (head == NULL)
		{
			head = new_node;
			head->next = head;
		}
		else
		{
			p = head;
			while (p->next != head)
				p = p->next;
			p->next = new_node;
			new_node->next = head;
			head = new_node;
		}
	}
	else
	{
		p = head;
		for (int i = 0; i < pos - 1; i++)
			p = p->next;
		new_node->next = p->next;
		p->next = new_node;
	}
}

int CircularLL::Delete(int pos)
{
	int x;
	Node *p = head;
	if (pos < 0 || pos > Length())
		return -1;
	if (pos == 1)
	{
		while (p->next != head)
			p = p->next;
		x = head->data;
		if (p == head)
		{
			delete head;
			head = NULL;
		}
		else
		{
			p->next = head->next;
			delete head;
			head = p->next;
		}
	}
	else
	{
		Node *q;
		for (int i = 0; i < pos - 2; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		delete q;
	}
	return x;
}

void CircularLL::Display()
{
	Node *p = head;
	do
	{
		cout << p->data << " ";
		p = p->next;
	} while (p != head);
	cout << endl;
}

// void RDisplay(Node *p)
// {
// 	static int flag = 0;
// 	if (p != head || flag == 0)
// 	{
// 		flag = 1;
// 		cout << p->data << " ";
// 		RDisplay(p->next);
// 	}
// 	flag = 0;
// }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {5, 13, 9, 25, 1};
	CircularLL C(A, 5);
	C.Insert(3, 45);
	C.Display();
	cout << "Deleted element: " << C.Delete(2);

	return 0;
}