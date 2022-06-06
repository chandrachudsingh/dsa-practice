#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<functional>
using namespace std;

int main()
{
#ifndef ONLINE_JUDG			E
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	map<string, int> Map;
	// map < string, int, greater<>> Map;

	// Different ways to insert key and value pair in Map
	Map["Chotu"] = 9;
	Map["Amit"] = 4;
	Map.insert(make_pair("Bot", 7));

	// first for 'Key' and second for 'value'
	for (auto &e : Map)
		cout << e.first << " " << e.second << endl;

	// cout << Map["Chotu"] << endl;
	return 0;
}

// // Using Container in container
// int main()
// {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	// using this we can store more than 1 value for a key
// 	map<string, vector<int>> Map;
// 	Map["Chotu"].push_back(9);
// 	Map["Amit"].push_back(4);
// 	Map["Amit"].push_back(8);

// 	// first for 'Key' and second for 'value'
// 	for (auto &e1 : Map)
// 	{
// 		cout << e1.first << endl;
// 		for (auto & e2 : e1.second)
// 			cout << e2 << " ";
// 		cout << endl;
// 	}

// 	// cout << Map["Chotu"] << endl;
// 	return 0;
// }