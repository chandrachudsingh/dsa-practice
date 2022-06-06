#include<iostream>
using namespace std;

class LTriangular
{
private:
	int n;
	int *A;

public:
	LTriangular()
	{
		n = 2;
		A = new int[2 * (2 + 1) / 2];
	}
	LTriangular(int n)
	{
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~LTriangular()
	{
		delete []A;
	}

	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension() { return n; };
};

void LTriangular::Set(int i, int j, int x)
{
	if (i >= j)
		A[(i * (i - 1) / 2) + (j - 1)] = x;
}

int LTriangular::Get(int i, int j)
{
	if (i >= j)
		return A[(i * (i - 1) / 2) + (j - 1)];		// for storing row-by-row
	return 0;
}

void LTriangular::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j)
				cout << A[(i * (i - 1) / 2) + (j - 1)] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{
	int d;
	cout << "Enter Dimensions:";
	cin >> d;

	LTriangular L(d);
	// As in maths the index starts from 1

	int x;
	cout << "Enter all Elements:\n";
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			L.Set(i, j, x);
		}
	}
	L.Display();

	cout << endl;
	cout << L.Get(2, 3) << endl;
	cout << L.Get(3, 2) << endl;
	return 0;
}