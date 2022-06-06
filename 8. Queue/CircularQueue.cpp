#include<iostream>
using namespace std;

template<class T>
class CircularQueue
{
private:
	int size, front, rear;
	T *q;

public:
	CircularQueue();
	CircularQueue(int size);
	void Display();
	void enqueue(T x);
	T deque();
	T first();
	T last();
	bool isEmpty();
	bool isFull();
};

template<class T>
CircularQueue<T>::CircularQueue()
{
	cout << "Enter size:\n";
	cin >> size;
	front = rear = 0;
	q = new T[size];
}

template<class T>
CircularQueue<T>::CircularQueue(int size)
{
	this->size = size;
	front = rear = 0;
	q = new T[size];
}

template<class T>
void CircularQueue<T>:: Display()
{
	int i = front + 1;
	do
	{
		cout << q[i] << " ";
		i = (i + 1) % size;
	} while (i != (rear + 1) % size);
	cout << "\n";
}

template<class T>
void CircularQueue<T>::enqueue(T x)
{
	if ((rear + 1) % size == front)
	{
		cout << "Queue is Full";
		return;
	}
	rear = (rear + 1) % size;
	q[rear] = x;
}

template<class T>
T CircularQueue<T>::deque()
{
	T x = -1;
	if (front == rear)
	{
		cout << "Queue is empty";
		return x;
	}
	front = (front + 1) % size;
	x = q[front];
	return x;
}

template<class T>
T CircularQueue<T>::first()
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
T CircularQueue<T>::last()
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
bool CircularQueue<T>::isEmpty()
{
	return front == rear;
}

template<class T>
bool CircularQueue<T>::isFull()
{
	return (rear + 1) % size == front;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	CircularQueue<int> Q(5);
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