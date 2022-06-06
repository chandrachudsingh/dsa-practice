#include<iostream>
#include<math.h>
using namespace std;

class terms
{
public:
	int coeff, exp;
};

class Poly
{
private:
	int n;
	terms *t;

public:
	Poly() {}
	Poly(int n)
	{
		this->n = n;
		t = new terms[this->n];
	}

	void create()
	{
		cout << "Enter no. of terms:\n";
		cin >> n;

		t = new terms[n];
		cout << "Enter the coefficients & exponents of poynomial:\n";
		for (int i = 0; i < n; i++)
			cin >> t[i].coeff >> t[i].exp;
	}

	void display()
	{
		for (int i = 0; i < n; i++)
		{
			cout << t[i].coeff << "x^" << t[i].exp;
			if (i != n - 1)
				cout << "+";
		}
		cout << endl;
	}

	int evaluate(int x)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += t[i].coeff * pow(x, t[i].exp);
		return sum;
	}

	Poly operator +(Poly &p)
	{
		int i, j, k;
		Poly *add = new Poly(n + p.n);

		i = j = k = 0;
		while (i < n && j < p.n)
		{
			if (t[i].exp > p.t[j].exp)
				add->t[k++] = t[i++];
			else if (t[i].exp < p.t[j].exp)
				add->t[k++] = p.t[j++];
			else
			{
				add->t[k] = t[i];
				add->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
			}
		}
		for (; i < n; i++)
			add->t[k++] = t[i];
		for (; j < p.n; j++)
			add->t[k++] = p.t[j];
		add->n = k;

		return *add;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Poly p1;
	p1.create();
	p1.display();

	// int x;
	// cout << "Enter value of x to evaluate:\n";
	// cin >> x;
	// cout << "p(x) = " << p1.evaluate(x) << endl;

	Poly p2;
	p2.create();
	p2.display();

	Poly p3 = p1 + p2;
	p3.display();

	return 0;
}