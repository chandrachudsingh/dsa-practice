#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T> void print_queue(T& q)
{
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << "\n";
}

int main()
{
	{
		priority_queue<int> q;
		for (int e : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			q.push(e);
		print_queue(q);
	}
	{
		priority_queue<int, vector<int>, greater<int>> q2;
		for (int e : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			q2.push(e);
		print_queue(q2);
	}
	// Using lambda to compare elements
	{
		auto cmp = [](int left, int right) { return (left) < (right); };
		priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);
		for (int e : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			q3.push(e);
		print_queue(q3);
	}
	return 0;
}