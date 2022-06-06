#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> que)
{
	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();    //remove from back
	}
}

int main()
{
	std::queue<int> que;
	que.push(2);
	que.push(3);
	que.push(4);
	print(que);
	return 0;
}