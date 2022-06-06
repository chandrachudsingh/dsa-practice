#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Queue
{
private:
	Node *front, *rear;

public:
	Queue() {front = rear = NULL;}

	void Display();
	void enqueue(int x);
	int deque();
	int first();
	int last();
	bool isEmpty();
	bool isFull();
};

void Queue::Display()
{
	Node *p = front;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void Queue::enqueue(int x)
{
	Node *t = new Node;
	if (t == NULL)
	{
		cout << "Queue full!";
		return;
	}

	t->data = x;
	t->next = NULL;
	if (front == NULL)
		front = rear = t;
	else
	{
		rear->next = t;
		rear = t;
	}
}

int Queue::deque()
{
	int x = -1;
	if (front == NULL)
	{
		cout << "Queue empty!";
		return x;
	}
	Node *p = front;
	front = front->next;
	x = p->data;
	delete p;
	return x;
}

int Queue::first()
{
	if (front == NULL)
	{
		cout << "Queue empty!";
		return -1;
	}
	return front->data;
}

int Queue::last()
{
	if (front == NULL)
	{
		cout << "Queue empty!";
		return -1;
	}
	return rear->data;
}

bool Queue::isFull()
{
	Node *t = new Node;
	return t == NULL;
}

bool Queue::isEmpty()
{
	return front == NULL;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Queue Q;
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.enqueue(40);
	Q.enqueue(50);
	Q.enqueue(60);
	Q.enqueue(70);
	Q.Display();
	cout << "First element: " << Q.first() << "\n";
	cout << "last element: " << Q.last() << "\n";

	cout << "Dequeued element: " << Q.deque() << "\n";
	return 0;
}