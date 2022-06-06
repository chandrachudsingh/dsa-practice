#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;

// int main()
// {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	multiset<int> Multiset = {5, 2, 4, 3, 2, 5};
// 	Multiset.insert(20);    // insert an element
// 	// multiset<int, greater<>> Set = {5, 2, 4, 3, 2, 5};
// 	for (const auto& e : Multiset)
// 		cout << e << endl;

// 	return 0;
// }


// For User-defined datatype
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

	// multiset<Person> Multiset = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "John"}};
	multiset<Person, greater<Person>> Multiset = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "John"}};
	for (const auto& e : Multiset)
		cout << e.age << " " << e.name << endl;

	return 0;
}