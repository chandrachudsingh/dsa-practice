#include<iostream>
using namespace std;

class TridiagonalMatrix
{
private:
	int n;
	int *A;

public:
	TridiagonalMatrix()
	{
		n = 2;
		A = new int[3 * 2 - 2];
	}
	TridiagonalMatrix(int n)
	{
		this->n = n;
		A = new int[3 * n - 2];
	}
	~TridiagonalMatrix()
	{
		delete []A;
	}

	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension() { return n; };
};

void TridiagonalMatrix::Set(int i, int j, int x)
{
	if (i - j == 1)
		A[i - 1] = x;
	else if (i - j == 0)
		A[n - 1 + i - 1] = x;
	else if (i - j == -1)
		A[2 * n - 1 + i - 1] = x;
}

int TridiagonalMatrix::Get(int i, int j)
{
	if (i - j == 1)
		return A[i - 1];
	else if (i - j == 0)
		return A[n - 1 + i - 1];
	else if (i - j == -1)
		return A[2 * n - 1 + i - 1];
	return 0;
}

void TridiagonalMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - j == 1)
				cout << A[i - 1] << " ";
			else if (i - j == 0)
				cout << A[n - 1 + i - 1] << " ";
			else if (i - j == -1)
				cout << A[2 * n - 1 + i - 1] << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
}

int main()
{
	int d;
	cout << "Enter Dimensions:";
	cin >> d;

	TridiagonalMatrix T(d);
	// As in maths the index starts from 1

	int x;
	cout << "Enter all Elements:\n";
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			T.Set(i, j, x);
		}
	}
	T.Display();

	cout << endl;
	cout << T.Get(2, 3) << endl;
	cout << T.Get(3, 2) << endl;
	return 0;
}