#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
	forward_list<int> list1 = {5, 4, 4, 6, 2, 4};
	forward_list<int> list2 = {7, 6, 1, 9};

	list1.insert_after(list1.begin(), 8);	//insert after some index
	list1.emplace_after(list1.begin(), 8);	//insert after some index

	// list1.sort();
	// list2.reverse();
	// list1.merge(list2);

	// list1.unique();    // removes only adjacent duplicate element
	// list1.remove(2);	// removes all the matching entries
	list1.remove_if([] (int n) {	//also check this lambda exp. in C++
		return n > 4;
	});

	// Remove some data from one list and put in another
	list1.splice_after(list1.begin(), list2);
	for (auto& e : list1)
		cout << e << endl;
	// cout << "Size of list2: " << std::distance(list2.begin(), list2.end()) << endl;
	return 0;
}