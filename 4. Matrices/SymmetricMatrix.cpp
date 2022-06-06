#include<iostream>
using namespace std;

class SymmetricMatrix
{
private:
	int n;
	int *A;

public:
	SymmetricMatrix()
	{
		n = 2;
		A = new int[2 * (2 + 1) / 2];
	}
	SymmetricMatrix(int n)
	{
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~SymmetricMatrix()
	{
		delete []A;
	}

	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension() { return n; };
};

void SymmetricMatrix::Set(int i, int j, int x)
{
	if (i >= j)
		A[(i * (i - 1) / 2) + (j - 1)] = x;
}

int SymmetricMatrix::Get(int i, int j)
{
	if (i >= j)
		return A[(i * (i - 1) / 2) + (j - 1)];		// for storing row-by-row
	return 0;
}

void SymmetricMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j)
				cout << A[(i * (i - 1) / 2) + (j - 1)] << " ";
			else
				cout << A[(j * (j - 1) / 2) + (i - 1)] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int d;
	cout << "Enter Dimensions:";
	cin >> d;

	SymmetricMatrix S(d);
	// As in maths the index starts from 1

	int x;
	cout << "Enter all Elements:\n";
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			S.Set(i, j, x);
		}
	}
	S.Display();

	cout << endl;
	cout << S.Get(2, 3) << endl;
	cout << S.Get(3, 2) << endl;
	return 0;
}