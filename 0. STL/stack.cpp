#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> stk)
{
	while (!stk.empty())
	{
		cout << stk.top() << endl;
		stk.pop();    //remove from back
	}
}

int main()
{
	std::stack<int> stk;
	stk.push(2);
	stk.push(3);
	stk.push(4);
	print(stk);
	return 0;
}