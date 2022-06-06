#include<iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

class Tree
{
private:
	Node *root;

public:
	Tree() {root = NULL;}
	void CreateTree();
	void Preorder() { Preorder(root);}  //Passing private parameter in constructor
	void Preorder(Node *p);
	void PreorderIter() { PreorderIter(root);}
	void PreorderIter(Node *p);
	void Postorder() { Postorder(root);}
	void Postorder(Node *p);
	void PostorderIter() { PostorderIter(root);}
	void PostorderIter(Node *p);
	void Inorder() { Inorder(root);}
	void Inorder(Node *p);
	void InorderIter() { InorderIter(root);}
	void InorderIter(Node *p);
	void Levelorder() { Levelorder(root);}
	void Levelorder(Node *p);
	int Height() { Height(root);}
	int Height(Node *p);
	int Count() { Count(root);}
	int Count(Node *p);
	int CountLeaf() { CountLeaf(root);}
	int CountLeaf(Node *p);
	int CountNonLeaf() { CountNonLeaf(root);}
	int CountNonLeaf(Node *p);
	int searchInorder(int inArray[], int inStart, int inEnd, int data);
	Node* BuiltTreeFromTraversals(int inorder[], int preorder[], int inStart, int inEnd);
	Node* newNode(int data);
};

void Tree::CreateTree()
{
	Node *p, *t;
	int x;
	Queue Q(100);

	cout << "Enter root value: ";
	cin >> x;
	root = new Node;
	root->data = x;
	root->left = root->right = NULL;
	Q.enqueue(root);

	while (!Q.isEmpty())
	{
		p = Q.dequeue();
		cout << "Enter left child of " << p->data << ": ";
		cin >> x;
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->left = t->right = NULL;
			p->left = t;
			Q.enqueue(t);
		}

		cout << "Enter right child of " << p->data << ": ";
		cin >> x;
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->left = t->right = NULL;
			p->right = t;
			Q.enqueue(t);
		}
	}
}

void Tree::Preorder(Node *p)
{
	if (p)
	{
		cout << p->data << " ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

void Tree::PreorderIter(Node *p)
{
	Stack<Node*> st(100);
	while (p != NULL || !st.isEmpty())
	{
		if (p != NULL)
		{
			cout << p->data << " ";
			st.push(p);
			p = p->left;
		}
		else
		{
			p = st.pop();
			p = p->right;
		}
	}
}

void Tree::Inorder(Node *p)
{
	if (p)
	{
		Inorder(p->left);
		cout << p->data << " ";
		Inorder(p->right);
	}
}

void Tree::InorderIter(Node *p)
{
	Stack<Node*> st(100);
	while (p != NULL || !st.isEmpty())
	{
		if (p != NULL)
		{
			st.push(p);
			p = p->left;
		}
		else
		{
			p = st.pop();
			cout << p->data << " ";
			p = p->right;
		}
	}
}

void Tree::Postorder(Node *p)
{
	if (p)
	{
		Postorder(p->left);
		Postorder(p->right);
		cout << p->data << " ";
	}
}

void Tree::PostorderIter(Node *p)
{
	Stack<long long int> st(100);
	long long int temp;
	while (p != NULL || !st.isEmpty())
	{
		if (p != NULL)
		{
			st.push((long long int)p);
			p = p->left;
		}
		else
		{
			temp = st.pop();
			if (temp > 0)
			{
				st.push(temp * -1);
				p = ((Node*)temp)->right;
			}
			else
			{
				cout << ((Node*)(-1 * temp))->data << " ";
				p = NULL;
			}
		}
	}
}

void Tree::Levelorder(Node *p)
{
	Queue Q(100);
	cout << p->data << " ";
	Q.enqueue(root);
	while (!Q.isEmpty())
	{
		p = Q.dequeue();
		if (p->left)
		{
			cout << p->left->data << " ";
			Q.enqueue(p->left);
		}
		if (p->right)
		{
			cout << p->right->data << " ";
			Q.enqueue(p->right);
		}
	}
}

int Tree::Height(Node *p)
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

int Tree::Count(Node *p)
{
	if (p)
		return Count(p->left) + Count(p->right) + 1;
	return 0;
}

int Tree::CountLeaf(Node *p)
{
	int x, y;
	if (p)
	{
		x = CountLeaf(p->left);
		y = CountLeaf(p->right);
		if (p->left == NULL && p->right == NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

int Tree::CountNonLeaf(Node *p)
{
	int x, y;
	if (p)
	{
		x = CountLeaf(p->left);
		y = CountLeaf(p->right);
		if (p->left != NULL || p->right != NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

int Tree::searchInorder(int inArray[], int inStart, int inEnd, int data)
{
	for (int i = inStart; i <= inEnd; i++)
	{
		if (inArray[i] == data)
			return i;
	}
	return -1;
}


Node* Tree::BuiltTreeFromTraversals(int inorder[], int preorder[], int inStart, int inEnd)
{
	static int preIndex = 0;
	if (inStart > inEnd)
		return NULL;

	Node* node = newNode(preorder[preIndex++]);
	if (inStart == inEnd)
		return node;

	int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
	node->left = BuiltTreeFromTraversals(inorder, preorder, inStart, splitIndex - 1);
	node->right = BuiltTreeFromTraversals(inorder, preorder, splitIndex + 1, inEnd);

	return node;
}

Node* Tree::newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int main()
{
	Tree T;
	T.CreateTree();
	T.Preorder();
	cout << endl;
	T.Inorder();
	cout << endl;
	T.PostorderIter();
	cout << endl;
	T.Levelorder();
	cout << endl;
	cout << "Height of the Tree- " << T.Height() << endl;
	cout << "No. of nodes in the Tree- " << T.Count() << endl;

	Tree bt;
	int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
	int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
	Node* node = bt.BuiltTreeFromTraversals(inorder, preorder, 0, sizeof(inorder) / sizeof(inorder[0]) - 1);
//	bt.Preorder(node);

	return 0;
}
