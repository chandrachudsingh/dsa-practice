#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<list>
using namespace std;

int main()
{
	list<int> lst(10);
	iota(lst.begin(), lst.end(), -5);
	for (auto elm : lst)
		cout << elm << endl;

	cout << '\n';
	vector<list<int>::iterator> vec(lst.size());
	iota(vec.begin(), vec.end(), lst.begin());
	for (auto elm : vec)
		cout << *elm << endl;

	return 0;
}