#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> Vec{4, 3, 2, 1, 6, 1, 10};
	// first element is always sorted, so min value is returned will be 1
	// auto it = is_sorted_until(Vec.begin(), Vec.end());
	auto it = is_sorted_until(Vec.begin(), Vec.end(), greater<int>());
	auto diff = distance(Vec.begin(), it);
	cout << diff << endl;
	return 0;
}