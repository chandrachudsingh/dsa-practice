#include<iostream>
#include<vector>
using namespace std;

void print(pair<int, int>& obj) { cout << obj.first << " " << obj.second << endl; }

int main()
{
	{
		std::pair<int, int> obj(10, 20);
		print(obj);
	}
	{
		std::pair<int, int> obj = std::make_pair(10, 20);
		print(obj);
	}
	{
		vector<pair<string, int>> list;
		list.push_back(make_pair("Rupesh", 30));
		list.push_back(make_pair("Hitesh", 33));
		list.push_back(pair<string, int>("Bhupendra", 24));
		list.push_back(pair<string, int>("Sagar", 10));
		for (auto& e : list)
			cout << e.first << " " << e.second << endl;
	}
}