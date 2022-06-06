#include<iostream>
#include<deque>
using namespace std;

void print(const deque<int>& dq) { for (int num : dq) cout << num << " "; cout << endl; }

int main()
{
	{
		std::deque<int> dq = {2, 3, 4};
		dq.push_front(1);
		dq.push_back(5);
		print(dq);
	}
	{
		std::deque<int> dq = {1, 2, 3, 4, 5};
		dq.pop_front();
		dq.pop_back();
		print(dq);
	}
}