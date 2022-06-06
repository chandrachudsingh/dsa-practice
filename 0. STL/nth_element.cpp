#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
	vector<int> v{4, 3, 5, 2, 6, 1, 10, 8, 3, 7};
	nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
	cout << "The median is: " << v[v.size() / 2] << '\n';

	nth_element(v.begin(), v.begin() + 1, v.end(), greater<int>());
	cout << "The second largest element is: " << v[1] << '\n';

	return 0;
}