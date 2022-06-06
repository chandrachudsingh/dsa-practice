#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	multimap<char, int> Multimap;
	// multimap <char, int, greater<>> Multimap;

	// different ways to insert in multimap
	Multimap.insert(pair<char, int>('a', 1));
	Multimap.insert(make_pair('a', 2));
	Multimap.insert(make_pair('a', 3));
	Multimap.insert(make_pair('b', 4));
	Multimap.insert(make_pair('c', 5));

	// find() - returns any maching pair of a key
	auto pair = Multimap.find('a');
	cout << "Found: " << pair->first << " " << pair->second << endl;

	// Returns true or false
	// cout << "Contains 'b': " << Multimap.contains('b') << endl;

	// Returns Lower Bound/Upper bound
	// auto range = Multimap.lower_bound('a');
	// cout << "Lower Bound: " << range->first << " " << range->second << endl;

	auto range = Multimap.upper_bound('a');
	cout << "Upper Bound: " << range->first << " " << range->second << endl;


	// Iterate over multimap
	for (auto &e : Multimap)
		cout << e.first << " " << e.second << endl;
	cout << endl;

	// Get all the pairs of given key
	// pair<multimap<char, int>::iterator, multimap<char, int>::iterator> range = Multimap.equal_range('a');
	// OR
	// auto range = Multimap.equal_range('a');
	// for (auto i = range.first; i != range.second; i++)
	// 	cout << i->first << " " << i->second << endl;
	// return 0;


}