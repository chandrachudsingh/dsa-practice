#include<iostream>
using namespace std;

template<class T>
class Queue
{
private:
	int size, front, rear;
	T *q;

public:
	Queue();
	Queue(int size);
	void Display();
	void enqueue(T x);
	T deque();
	T first();
	T last();
	bool isEmpty();
	bool isFull();
};

template<class T>
Queue<T>::Queue()
{
	cout << "Enter size:\n";
	cin >> size;
	front = rear = -1;
	q = new T[size];
}

template<class T>
Queue<T>::Queue(int size)
{
	this->size = size;
	front = rear = -1;
	q = new T[size];
}

template<class T>
void Queue<T>:: Display()
{
	for (int temp = front + 1; temp <= rear; temp++)
		cout << q[temp] << " ";
	cout << "\n";
}

template<class T>
void Queue<T>::enqueue(T x)
{
	if (rear == size - 1)
	{
		cout << "Queue is Full";
		return;
	}
	q[++rear] = x;
}

template<class T>
T Queue<T>::deque()
{
	T x = -1;
	if (front == rear)
	{
		cout << "Queue is empty";
		return x;
	}
	x = q[++front];
	return x;
}

template<class T>
T Queue<T>::first()
{
	T x = -1;
	if (front == rear)
	{
		cout << "Queue is empty";
		return x;
	}
	x = q[front + 1];
	return x;
}

template<class T>
T Queue<T>::last()
{
	T x = -1;
	if (front == rear)
	{
		cout << "Queue is empty";
		return x;
	}
	x = q[rear];
	return x;
}

template<class T>
bool Queue<T>::isEmpty()
{
	return front == rear;
}

template<class T>
bool Queue<T>::isFull()
{
	return rear == size - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Queue<int> Q(5);
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.enqueue(40);
	Q.enqueue(50);
	Q.Display();
	cout << "First element: " << Q.first() << "\n";
	cout << "last element: " << Q.last() << "\n";

	cout << "Dequeued element: " << Q.deque() << "\n";
	return 0;
}