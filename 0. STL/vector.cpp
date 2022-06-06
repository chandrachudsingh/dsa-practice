// 1. Vector is a sequence container and also known as Dynamic array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

// ELEMENTS ACCESS
// at(), [], front(), back(), data()

// MODIFIERS
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(),
// swap(), erase(), clear()

// size(), capacity()

#include<iostream>
#include<vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// Declare
	vector<int> arr1;
	vector<int> arr2 (5, 20);
	vector<int> arr3 = {1, 2, 3, 4, 5}; // initializer list
	vector<int> arr4 {1, 2, 3, 4, 5}; // uniform initialization

	// Accessing Elements
	arr2[3] = 10;
	arr2.at(3) = 10;

	// reserve() - to avoid too much copying time
	// vector<int> vec;
	// vec.reserve(31);
	// OR
	vector<int> vec(31);
	for (int i = 0; i < 32; i++)
	{
		vec.push_back(i);
		cout << "Size:" << vec.size() << "\tCapacity:" << vec.capacity() << endl;
	}

	return 0;
}