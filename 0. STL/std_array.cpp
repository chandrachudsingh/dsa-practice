// 1. std::array is a container that encpsulates fixed size array.
// 2. array size is needed at compile time.
// 3. Assign by value is actually by value.
// 4. Access Elements:
// 		a. at()
// 		b. []
// 		c. front()
// 		d. back()
// 		e. data()  --> gives access to underlying array


#include<iostream>
#include<array>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// Declare
	std::array<int, 5> arr;

	// Initialization
	// std::array<int, 5> arr = {1, 2, 3, 4, 5}; // initializer list
	// std::array<int, 5> arr2 {1, 2, 3, 4, 5}; // uniform initialization

	// Assign using initializer list
	// std::array<int, 5> arr;
	// arr = {1, 2, 3, 4, 5};

	return 0;
}