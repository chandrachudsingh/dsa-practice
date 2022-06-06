#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> Vec{4, 3, 5, 2, 6, 1};
	vector<int>::iterator it = find(Vec.begin(), Vec.end(), 4);

	if (it == Vec.end())
		cout << "Not found" << endl;
	else
		cout << "Found" << endl;
	return 0;
}