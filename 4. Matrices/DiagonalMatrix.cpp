#include<iostream>
using namespace std;

class Diagonal
{
private:
	int n;
	int *A;

public:
	Diagonal()
	{
		n = 2;
		A = new int[n];
	}
	Diagonal(int n)
	{
		this->n = n;
		A = new int[n];
	}
	~Diagonal()
	{
		delete []A;
	}

	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
};

void Diagonal::Set(int i, int j, int x)
{
	if (i == j)
		A[i - 1] = x;
}

int Diagonal::Get(int i, int j)
{
	if (i == j)
		return A[i - 1];
	else
		return 0;
}

void Diagonal::Display()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				cout << A[i] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{

	Diagonal D(5);
	// As in maths the index starts from 1
	D.Set(1, 1, 9);
	D.Set(2, 2, 4);
	D.Set(3, 3, 6);
	D.Set(4, 4, 1);
	D.Set(5, 5, 5);
	D.Display();

	cout << endl;

	cout << D.Get(2, 1) << endl;
	cout << D.Get(2, 2) << endl;
}