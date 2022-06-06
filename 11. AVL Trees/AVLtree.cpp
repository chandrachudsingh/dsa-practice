#include<iostream>
using namespace std;

class Node
{
public:
	int data, height;
	Node *left, *right;
};

class AVL
{
public:
	Node *root;

public:
	AVL() {root = NULL;}

	int NodeHeight(Node *p);
	int BalanceFactor(Node *p);
	void Insert(int key);
	Node* RInsert(Node *t, int key);
	Node* Delete(Node *p, int key);
	int Height(Node *p);
	Node* InPre(Node *p);
	Node* InSucc(Node *p);
	Node* LLRotation(Node *p);
	Node* LRRotation(Node *p);
	Node* RRRotation(Node *p);
	Node* RLRotation(Node *p);
	void Inorder(Node *p);
};

int AVL::BalanceFactor(Node *p)
{
	int hl = p && p->left ? p->left->height : 0;
	int hr = p && p->right ? p->right->height : 0;
	return hl - hr;
}

int AVL::NodeHeight(Node *p)
{
	int hl = p && p->left ? p->left->height : 0;
	int hr = p && p->right ? p->right->height : 0;
	return hl > hr ? hl + 1 : hr + 1;
}

Node* AVL::RInsert(Node *t, int key)
{
	Node *p;
	if (t == NULL)
	{
		p = new Node;
		p->data = key;
		p->height = 1;
		p->left = p->right = NULL;
		return p;
	}

	if (key < t->data)
		t->left = RInsert(t->left, key);
	else if (key > t->data)
		t->right = RInsert(t->right, key);

	p->height = NodeHeight(p);
	if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)
		return LLRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)
		return LRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)
		return RRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)
		return RLRotation(p);

	return t;
}

// Replace the deleted node with its Inorder Predecessor or Inorder Successor
Node *AVL::Delete(Node *p, int key)
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

	// Update height
	p->height = NodeHeight(p);

	// Balance factor and Rotation
	if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1) //L1 Rotation
		return LLRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1) //L-1 Rotation
		return LRRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 0) //L0 Rotation
		return LLRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->right) == 1) //R1 Rotation
		return RLRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->right) == -1) //R-1 Rotation
		return RRRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->right) == 0) //R0 Rotation
		return RRRotation(p);

	return p;
}

int AVL::Height(Node *p)
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
Node* AVL::InPre(Node *p)
{
	while (p && p->right)
		p = p->right;
	return p;
}

// Inorder Successor
Node* AVL::InSucc(Node *p)
{
	while (p && p->left)
		p = p->left;
	return p;
}

Node* AVL::LLRotation(Node* p)
{
	Node *pl = p->left;
	Node *plr = pl->right;

	pl->right = p;
	p->left = plr;
	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	if (p == root)
		root = pl;

	return pl;
}

Node* AVL::LRRotation(Node* p)
{
	Node *pl = p->left;
	Node *plr = pl->right;

	pl->right = plr->left;
	p->left = plr->right;
	plr->left = pl;
	plr->right = p;
	pl->height = NodeHeight(pl);
	p->height = NodeHeight(p);
	plr->height = NodeHeight(plr);

	if (p == root)
		root = plr;

	return plr;
}

Node* AVL::RRRotation(Node* p)
{
	Node *pr = p->right;
	Node *prl = pr->left;

	pr->left = p;
	p->right = prl;
	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if (p == root)
		root = pr;

	return pr;
}

Node* AVL::RLRotation(Node* p)
{
	Node *pr = p->right;
	Node *prl = pr->left;

	p->right = prl->left;
	pr->left = prl->right;
	prl->left = p;
	prl->right = pr;
	pr->height = NodeHeight(pr);
	p->height = NodeHeight(p);
	prl->height = NodeHeight(prl);

	if (p == root)
		root = prl;

	return prl;
}

void AVL::Inorder(Node *p)
{
	if (p)
	{
		Inorder(p->left);
		cout << p->data << " ";
		Inorder(p->right);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	AVL T;

	// LL
	// T.root = T.RInsert(T.root, 10);
	// T.RInsert(T.root, 5);
	// T.RInsert(T.root, 2);

	// LR
	// T.root = T.RInsert(T.root, 10);
	// T.RInsert(T.root, 2);
	// T.RInsert(T.root, 5);

	// RR
	// T.root = T.RInsert(T.root, 2);
	// T.RInsert(T.root, 5);
	// T.RInsert(T.root, 10);

	// RL
	T.root = T.RInsert(T.root, 2);
	T.RInsert(T.root, 10);
	T.RInsert(T.root, 5);

	T.Inorder(T.root);
	cout << endl;

	AVL T2;

	int A[] = {10, 20, 30, 25, 28, 27, 5};
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
		T2.root = T2.RInsert(T2.root, A[i]);
	T2.Inorder(T2.root);
	cout << endl;

	T2.Delete(T2.root, 28);
	T2.Inorder(T2.root);
	cout << endl;

	return 0;
}