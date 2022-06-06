#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;
};

class Queue
{
private:
	int front, rear, size;
	Node **q;

public:
	Queue()
	{
		front = rear = 0;
		size = 10;
		q = new Node*[size];
	}

	Queue(int size)
	{
		front = rear = 0;
		this->size = size;
		q = new Node*[size];
	}

	void Display();
	void enqueue(Node *x);
	Node* dequeue();
	bool isEmpty();
	bool isFull();
};

void Queue::Display()
{
	for (int temp = front + 1; temp <= rear; temp++)
		cout << q[temp] << " ";
	cout << "\n";
}

void Queue::enqueue(Node *x)
{
	if (rear == size - 1)
	{
		cout << "Queue full!";
		return;
	}
	q[++rear] = x;
}

Node* Queue::dequeue()
{
	Node* x = NULL;
	if (front == rear)
	{
		cout << "Queue is empty";
		return x;
	}
	x = q[++front];
	return x;
}

bool Queue::isEmpty()
{
	return front == rear;
}

bool Queue::isFull()
{
	return rear == size - 1;
}

#endif