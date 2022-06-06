#include<iostream>
using namespace std;

class UTriangular
{
private:
	int n;
	int *A;

public:
	UTriangular()
	{
		n = 2;
		A = new int[2 * (2 + 1) / 2];
	}
	UTriangular(int n)
	{
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~UTriangular()
	{
		delete []A;
	}

	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension() { return n; };
};

void UTriangular::Set(int i, int j, int x)
{
	if (i <= j)
		A[((j - 1)*n - (i - 2) * (i - 1) / 2) + (j - i)] = x;
}

int UTriangular::Get(int i, int j)
{
	if (i <= j)
		return A[((j - 1) * n - (i - 2) * (i - 1) / 2) + (j - i)];		// for storing row-by-row
	return 0;
}

void UTriangular::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i <= j)
				cout << A[((j - 1)*n - (i - 2) * (i - 1) / 2) + (j - i)] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int d;
	cout << "Enter Dimensions:";
	cin >> d;

	UTriangular U(d);
	// As in maths the index starts from 1

	int x;
	cout << "Enter all Elements:\n";
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			U.Set(i, j, x);
		}
	}
	U.Display();

	cout << endl;
	cout << U.Get(2, 3) << endl;
	cout << U.Get(3, 2) << endl;
	return 0;
}