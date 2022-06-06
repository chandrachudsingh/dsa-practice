#include<iostream>
#include<algorithm>
#include<string>
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

	// COPY_N
	vector<int> to_vector1;
	copy_n(from_vector.begin(), 4, back_inserter(to_vector1));
	print(to_vector1);

	// COPY_BACKWARD
	vector<int> to_vector2(15);
	copy_backward(from_vector.begin(), from_vector.end(), to_vector2.end());
	print(to_vector2);

	return 0;
}