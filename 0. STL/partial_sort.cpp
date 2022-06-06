#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> Vec{4, 3, 5, 2, 6, 1, 10, 8, 3, 7};
	// partial_sort(Vec.begin(), Vec.begin() + 4, Vec.end()-2);
	partial_sort(Vec.begin(), Vec.begin() + 4, Vec.end(), greater<int>());
	for (auto elm : Vec)
		cout << elm << " ";
	return 0;
}