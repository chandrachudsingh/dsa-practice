#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;

class Person
{
public:
	float age;
	string name;

	// Compare function, so that set can store the user deined datatype in sorted order
	// For normal sorted < should be overloaded
	bool operator < (const Person& rhs) const { return age < rhs.age; }
	// For reverse sorted > should be overloaded
	bool operator > (const Person& rhs) const { return age > rhs.age; }
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// Declare
	// set<int> Set = {5, 2, 3, 1, 4, 1, 2, 3, 4, 5};
	// for reverse sorted set
	// set<int, greater<int>> Set = {5, 2, 3, 1, 4, 1, 2, 3, 4, 5};
	// for (const auto& e : Set)
	// 	cout << e << endl;

	set<Person> Set = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "John"}};
	// set<Person, greater<Person>> Set = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "John"}};
	for (const auto& e : Set)
		cout << e.age << " " << e.name << endl;

	return 0;
}