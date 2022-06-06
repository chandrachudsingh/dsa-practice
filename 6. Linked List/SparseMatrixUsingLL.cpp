#include<iostream>
using namespace std;

class Node
{
public:
	int col, val;
	Node *next;
};

class SparseMatrixUsingLL
{
private:
	int m, n;
	Node **A;
public:
	SparseMatrixUsingLL(int m, int n);
	~SparseMatrixUsingLL();

	void Display();
	void read();
	SparseMatrixUsingLL operator +(SparseMatrixUsingLL &s);
};

SparseMatrixUsingLL::SparseMatrixUsingLL(int m, int n)
{
	this->m = m;
	this->n = n;
	A = new Node*[m];    //create array in heap
	for (int i = 0; i < m; i++)
		A[i] = NULL;
}

SparseMatrixUsingLL::~SparseMatrixUsingLL()
{
	Node *p, *q;
	for (int i = 0; i < m; i++)
	{
		p = A[i];
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
		}
	}
	delete [] A;
}

void SparseMatrixUsingLL::read()
{
	Node *new_node, *tail;
	int num;
	for (int i = 0; i < m; i++)
	{
		cout << "Enter no. of non-zero elements in row " << i + 1 << ": ";
		cin >> num;

		cout << "Enter col no. and value in the row: " << endl;
		for (int j = 0; j < num; j++)
		{
			if (A[i] == NULL)
			{
				new_node = new Node;
				cin >> new_node->col >> new_node->val;
				new_node->next = NULL;
				A[i] = new_node;
				tail = new_node;
			}
			else
			{
				new_node = new Node;
				cin >> new_node->col >> new_node->val;
				new_node->next = NULL;
				tail->next = new_node;
				tail = new_node;
			}
		}
	}
}

SparseMatrixUsingLL SparseMatrixUsingLL::operator +(SparseMatrixUsingLL &s)
{
	// if (m != s.m || n != s.n)
	// 	return NULL;
	SparseMatrixUsingLL *Add = new SparseMatrixUsingLL(m, n);
	Node *p, *q, *new_node, *tail;
	for (int i = 0; i < m; i++)
	{
		p = A[i];
		q = s.A[i];
		while (p && q)
		{
			new_node = new Node;
			new_node->next = NULL;
			if (p->col < q->col)
			{
				new_node->col = p->col;
				new_node->val = p->val;
				p = p->next;
			}
			else if (p->col > q->col)
			{
				new_node->col = q->col;
				new_node->val = q->val;
				q = q->next;
			}
			else
			{
				new_node->col = p->col;
				new_node->val = p->val + q->val;
				p = p->next;
				q = q->next;
			}

			if (Add->A[i] == NULL)
				Add->A[i] = new_node;
			else
				tail->next = new_node;
			tail = new_node;
		}

		if (p)
		{
			while (p)
			{
				new_node = new Node;
				new_node->next = NULL;
				new_node->col = p->col;
				new_node->val = p->val;
				p = p->next;

				if (Add->A[i] == NULL)
					Add->A[i] = new_node;
				else
					tail->next = new_node;
				tail = new_node;
			}
		}
		if (q)
		{
			while (q)
			{
				new_node = new Node;
				new_node->next = NULL;
				new_node->col = q->col;
				new_node->val = q->val;
				q = q->next;

				if (Add->A[i] == NULL)
					Add->A[i] = new_node;
				else
					tail->next = new_node;
				tail = new_node;
			}
		}
	}
	return *Add;
}

void SparseMatrixUsingLL::Display()
{
	Node *p;
	for (int i = 0; i < m; i++)
	{
		p = A[i];
		for (int j = 0; j < n; j++)
		{
			if (p && j == p->col - 1)
			{
				cout << p->val << " ";
				p = p->next;
			}
			else
				cout << 0 << " ";
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

	SparseMatrixUsingLL S1(5, 6);
	S1.read();
	S1.Display();

	SparseMatrixUsingLL S2(5, 6);
	S2.read();
	S2.Display();

	SparseMatrixUsingLL S3 = S1 + S2;
	cout << "Addition:" << endl;
	S3.Display();

	return 0;
}