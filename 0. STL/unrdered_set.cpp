#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_set<int> Uset = {4, 1, 3, 6, 3, 2, 4};

	auto search = Uset.find(2);
	if (search != Uset.end())
		cout << "Found " << (*search) << '\n';
	else
		cout << "Not found\n";

	for (auto e : Uset)
		cout << e << " ";
	cout << endl;
	return 0;
}