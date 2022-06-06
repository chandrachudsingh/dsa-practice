#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	unordered_multimap<int, char> Ummap = {{5, 'd'}};
	Ummap.insert({1, 'a'});
	Ummap.insert(pair<int, char>(2, 'b'));
	Ummap.insert(make_pair(3, 'c'));
	Ummap.insert(make_pair(3, 'c'));

	for (auto& e : Ummap)
		cout << e.first << "-" << e.second << "\n";
	return 0;
}

// Seminar