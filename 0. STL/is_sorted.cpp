#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1. check Integral datatypes.

int main()
{
	vector<int> Vec{4, 3, 5, 2, 6, 1};
	sort(Vec.begin(), Vec.end());
	for (auto elm : Vec)
		cout << elm << " ";

	cout << '\n' << is_sorted(Vec.begin(), Vec.end());
	return 0;
}


// 2. check user defined datatypes.

// class Point
// {
// public:
// 	int x, y;
// 	Point(int x = 0, int y = 0): x{x}, y{y} {};
// 	bool operator < (const Point& p1) {
// 		return (x + y) < (p1.x + p1.y);
// 	}
// };

// int main()
// {
// 	vector<Point> Vec{{1, 2}, {3, 1}, {0, 1}};
// 	sort(Vec.begin(), Vec.end());
// 	for (auto elm : Vec)
// 		cout << elm.x << " " << elm.y << endl;
// 	cout << '\n' << is_sorted(Vec.begin(), Vec.end());
// 	return 0;
// }


// 3. check using a function object.

// struct {
// 	bool operator()(int a, int b) const
// 	{
// 		return a < b;
// 	}
// } customless;

// int main()
// {
// 	vector<int> Vec{4, 3, 5, 2, 6, 1};
// 	sort(Vec.begin(), Vec.end(), customless);
// 	for (auto elm : Vec)
// 		cout << elm << " ";
// 	cout << '\n' << is_sorted(Vec.begin(), Vec.end());
// 	return 0;
// }


// 4. check using a lambda function.

// int main()
// {
// 	vector<int> Vec{4, 3, 5, 2, 6, 1};
// 	sort(Vec.begin(), Vec.end(), [](int a, int b) { return a < b; });
// 	for (auto elm : Vec)
// 		cout << elm << " ";
// 	cout << '\n' << is_sorted(Vec.begin(), Vec.end());
// 	return 0;
// }