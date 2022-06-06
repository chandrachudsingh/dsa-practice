// Element themselves are priority.
/* Insert in Increasing order of priority
 and delete the last element of the array. */

#include<iostream>
using namespace std;

template<class T>
class PriorityQueue
{
private:
	int size, front, rear;
	T *q;

public:
	PriorityQueue();
	PriorityQueue(int size);
	void Display();
	void enqueue(T x);
	T deque();
	T first();
	T last();
	bool isEmpty();
	bool isFull();
};

template<class T>
PriorityQueue<T>::PriorityQueue()
{
	cout << "Enter size:\n";
	cin >> size;
	front = rear = -1;
	q = new T[size];
}

template<class T>
PriorityQueue<T>::PriorityQueue(int size)
{
	this->size = size;
	front = rear = -1;
	q = new T[size];
}

template<class T>
void PriorityQueue<T>:: Display()
{
	for (int temp = front + 1; temp <= rear; temp++)
		cout << q[temp] << " ";
	cout << "\n";
}

template<class T>
void PriorityQueue<T>::enqueue(T x)
{
	if (rear == size - 1)
	{
		cout << "Queue is Full";
		return;
	}

	q[++rear] = x;
	for (int i = rear - 1; i >= 0; i--)
	{
		if (q[i] < q[i + 1])
			swap(q[i], q[i + 1]);
	}
}

template<class T>
T PriorityQueue<T>::deque()
{
	T x = -1;
	if (front == rear)
	{
		cout << "Queue is empty";
		return x;
	}
	x = q[rear--];
	return x;
}

template<class T>
T PriorityQueue<T>::first()
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
T PriorityQueue<T>::last()
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
bool PriorityQueue<T>::isEmpty()
{
	return front == rear;
}

template<class T>
bool PriorityQueue<T>::isFull()
{
	return rear == size - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	PriorityQueue<int> Q(5);
	Q.enqueue(30);
	Q.enqueue(20);
	Q.enqueue(50);
	Q.enqueue(10);
	Q.enqueue(40);
	Q.enqueue(60);
	Q.Display();
	cout << "First element: " << Q.first() << "\n";
	cout << "last element: " << Q.last() << "\n";

	cout << "Dequeued element: " << Q.deque() << "\n";
	return 0;
}