#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<numeric>
using namespace std;

void print(vector<int>& vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	vector<int> from_vector(10);
	iota(from_vector.begin(), from_vector.end(), 0);

	vector<int> to_vector1(from_vector.size());
	copy(from_vector.begin(), from_vector.end(), to_vector1.begin());
	print(to_vector1);

	// OR, alternatively
	vector<int> to_vector2;
	copy(from_vector.begin(), from_vector.end(), back_inserter(to_vector2));
	print(to_vector2);

	// either way is equivalent to
	vector<int> to_vector = from_vector;
	// what is the benefits of copy function if we can do this..
	// Actually we can partially copy elements using copy() function.
	// copy(from_vector.begin()-2, from_vector.end()-6, to_vector1.begin());

	cout << "Odd numbers in to_vector are: ";
	vector<int> to_vector3(5);
	copy_if(from_vector.begin(), from_vector.end(), to_vector3.begin(), [](int x) { return (x % 2) == 1; });
	print(to_vector3);

	return 0;
}