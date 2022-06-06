#include<iostream>
#include "Stack.h"
using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;
};

class BST
{
private:
	Node *root;

public:
	BST() { root = NULL;}
	Node* getRoot() { return root; }
	Node* Search(int key);
	Node* RSearch(Node *t, int key);
	void Insert(int key);
	Node* RInsert(Node *t, int key);
	Node* Delete(Node *p, int key);
	void Inorder(Node *p);
	int Height(Node *p);
	Node* InPre(Node *p);
	Node* InSucc(Node *p);
	void CreateTreePre(int pre[], int n);
	Node* CreateTreePost(int post[], int start, int end);
};

Node* BST::RSearch(Node *t, int key)
{
	if (t == NULL)
		return NULL;
	if (key == t->data)
		return t;
	else if (key < t->data)
		return RSearch(t->left, key);
	else
		return RSearch(t->right, key);
}

Node* BST::Search(int key)
{
	Node *t = root;
	while (t)
	{
		if (key == t->data)
			return t;
		else if (key < t->data)
			t = t->left;
		else
			t = t->right;
	}
	return NULL;
}

void BST::Insert(int key)
{
	Node *t = root;
	Node *p = new Node;
	Node *r;
	p->data = key;
	p->left = p->right = NULL;
	if (root == NULL)
	{
		root = p;
		return;
	}

	while (t)
	{
		r = t;
		if (key == t->data)
			return;
		else if (key < t->data)
			t = t->left;
		else
			t = t->right;
	}

	if (key < r->data)
		r->left = p;
	else
		r->right = p;
}

Node* BST::RInsert(Node *t, int key)
{
	Node *p;
	if (t == NULL)
	{
		p = new Node;
		p->data = key;
		p->left = p->right = NULL;
		return p;
	}

	if (key < t->data)
		t->left = RInsert(t->left, key);
	else if (key > t->data)
		t->right = RInsert(t->right, key);
	return t;
}

// Replace the deleted node with its Inorder Predecessor or Inorder Successor
Node *BST::Delete(Node *p, int key)
{
	if (p == NULL)
		return NULL;
	if (p->left == NULL && p->right == NULL)
	{
		if (p == root)
			root = NULL;
		delete p;
		return NULL;
	}

	if (key < p->data)
		p->left = Delete(p->left, key);
	else if (key > p->data)
		p->right = Delete(p->right, key);
	else
	{
		Node *q = NULL;
		if (Height(p->left) > Height(p->right))
		{
			q = InPre(p->left);
			p->data = q->data;
			p->left = Delete(p->left, q->data);
		}
		else
		{
			q = InSucc(p->right);
			p->data = q->data;
			p->right = Delete(p->right, q->data);
		}
	}

	return p;
}

void BST::Inorder(Node *p)
{
	if (p)
	{
		Inorder(p->left);
		cout << p->data << " ";
		Inorder(p->right);
	}
}

int BST::Height(Node *p)
{
	if (p == NULL)
		return 0;
	int x = Height(p->left);
	int y = Height(p->right);
	if (x > y)
		return (x + 1);
	else
		return (y + 1);
}

// Inorder Predecessor
Node* BST::InPre(Node *p)
{
	while (p && p->right)
		p = p->right;
	return p;
}

// Inorder Successor
Node* BST::InSucc(Node *p)
{
	while (p && p->left)
		p = p->left;
	return p;
}

// O(n)
void BST::CreateTreePre(int pre[], int n)
{
	Stack<Node*> st(100);
	Node *t, *p;
	int i = 0;
	p = new Node;
	p->data = pre[i++];
	p->left = p->right = NULL;
	root = p;

	while (i < n)
	{
		if (pre[i] < p->data)
		{
			t = new Node;
			t->data = pre[i++];
			t->left = t->right = NULL;
			p->left = t;
			st.push(p);
			p = t;
		}
		else
		{
			if (pre[i] > p->data && pre[i] < st.stackTop()->data)
			{
				t = new Node;
				t->data = pre[i++];
				t->left = t->right = NULL;
				p->right = t;
				p = t;
			}
			else
				p = st.pop();
		}
	}
}

Node* BST::CreateTreePost(int post[], int start, int end)
{
	if (start > end)
		return NULL;

	Node* p = new Node;
	p->data = post[end];
	p->left = p->right = NULL;
	if (root == NULL)
		root = p;

	int i;
	for (i = end - 1; i >= start; i--)
		if (post[i] < p->data)
			break;

	p->left = CreateTreePost(post, start, i);
	p->right = CreateTreePost(post, i + 1, end - 1);
	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	BST B;
	int keys[] = {9, 15, 5, 20, 16, 8, 12, 3, 6};
	int len = sizeof(keys) / sizeof(keys[0]);
	for (int i = 0; i < len; i++)
	{
		// if (i == 0)
		// 	B.root = B.RInsert(B.getRoot(), keys[i]);
		// else
		// 	B.RInsert(B.getRoot(), keys[i]);
		B.Insert(keys[i]);
	}
	B.Inorder(B.getRoot());
	cout << endl;

	B.Delete(B.getRoot(), 9);
	B.Inorder(B.getRoot());
	cout << endl;

	Node *temp = B.Search(16);
	if (temp)
		cout << "Element " << temp->data << " is found" << endl;
	else
		cout << "Element not found" << endl;

	// Creating tree using traversals
	BST T1;
	int pre[] = {30 , 20 , 15 , 5 , 18 , 25 , 40 , 35 , 50 , 45 , 60};
	int lenPre = sizeof(pre) / sizeof(pre[0]);
	T1.CreateTreePre(pre, lenPre);
	cout << "Tree using Preorder: ";
	T1.Inorder(T1.getRoot());

	cout << endl;

	BST T2;
	int post[] = {5 , 18 , 15 , 25 , 20 , 35 , 45 , 60 , 50 , 40 , 30};
	int lenPost = sizeof(post) / sizeof(post[0]);
	T2.CreateTreePost(post, 0, lenPost - 1);
	cout << "Tree using Postorder: ";
	T2.Inorder(T2.getRoot());

	return 0;
}