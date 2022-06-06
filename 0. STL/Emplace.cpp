#include<iostream>
#include<set>
using namespace std;

class A
{
public:
	int x;
	A(int x = 0): x{x} {cout << "Construct" << endl;}
	A(const A& rhs) {x = rhs.x; cout << "Copy" << endl;}
};

bool operator < (const A& lhs, const A& rhs) {return lhs.x < rhs.x;}

int main()
{
	set<A> Set;
	// A a(10);
	// Set.insert(a);
	Set.emplace(10);
	return 0 ;
}