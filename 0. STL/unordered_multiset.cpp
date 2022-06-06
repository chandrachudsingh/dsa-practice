#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_multiset<int> Umset = {4, 1, 3, 6, 3, 2, 4, 9, 8, 10};

	auto search = Umset.find(2);
	if (search != Umset.end())
		cout << "Found " << (*search) << '\n';
	else
		cout << "Not found\n";

	for (auto e : Umset)
		cout << e << " ";
	cout << endl;
	cout << "No. of 4's present: " << Umset.count(4) << endl;
	return 0;
}