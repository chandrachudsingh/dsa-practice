#include<iostream>
#include<math.h>
using namespace std;

class Node
{
public:
	int coeff, exp;
	Node *next;
};

class Poly
{
private:
	int n;
	Node *head;

public:
	Poly() {head = NULL;}

	void create()
	{
		Node *new_node, *tail;
		cout << "Enter no. of terms:\n";
		cin >> n;

		cout << "Enter the coefficients & exponents of poynomial:\n";
		for (int i = 0; i < n; i++)
		{
			new_node = new Node;
			cin >> new_node->coeff >> new_node->exp;
			new_node->next = NULL;
			if (head == NULL)
				head = tail = new_node;
			else
			{
				tail->next = new_node;
				tail = new_node;
			}
		}
	}

	void display()
	{
		Node *p = head;
		while (p)
		{
			cout << p->coeff << "x^" << p->exp;
			p = p->next;
			if (p)
				cout << "+";
		}
		cout << endl;
	}

	int evaluate(int x)
	{
		int sum = 0;
		Node *p = head;
		while (p)
		{
			sum += p->coeff * pow(x, p->exp);
			p = p->next;
		}
		return sum;
	}

	Poly operator +(Poly &s)
	{
		Poly *Add = new Poly;
		Node *p = head, *q = s.head, * new_node, *tail;
		while (p && q)
		{
			if (p->exp > q->exp)
			{
				new_node = new Node;
				new_node->next = NULL;
				new_node->coeff = p->coeff;
				new_node->exp = p->exp;
				if (Add->head == NULL)
					Add->head = tail = new_node;
				else
				{
					tail->next = new_node;
					tail = new_node;
				}
				p = p->next;
			}
			else if (p->exp < q->exp)
			{
				new_node = new Node;
				new_node->next = NULL;
				new_node->coeff = q->coeff;
				new_node->exp = q->exp;
				if (Add->head == NULL)
					Add->head = tail = new_node;
				else
				{
					tail->next = new_node;
					tail = new_node;
				}
				q = q->next;
			}
			else
			{
				new_node = new Node;
				new_node->next = NULL;
				new_node->coeff = p->coeff + q->coeff;
				new_node->exp = p->exp;
				if (Add->head == NULL)
					Add->head = tail = new_node;
				else
				{
					tail->next = new_node;
					tail = new_node;
				}
				p = p->next;
				q = q->next;
			}
		}
		while (p)
		{
			new_node = new Node;
			new_node->next = NULL;
			new_node->coeff = p->coeff;
			new_node->exp = p->exp;
			if (Add->head == NULL)
				Add->head = tail = new_node;
			else
			{
				tail->next = new_node;
				tail = new_node;
			}
			p = p->next;
		}
		while (q)
		{
			new_node = new Node;
			new_node->next = NULL;
			new_node->coeff = q->coeff;
			new_node->exp = q->exp;
			if (Add->head == NULL)
				Add->head = tail = new_node;
			else
			{
				tail->next = new_node;
				tail = new_node;
			}
			q = q->next;
		}
		return *Add;
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
	cout << "Addition: " << endl;
	p3.display();

	return 0;
}