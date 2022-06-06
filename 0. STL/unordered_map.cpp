#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	unordered_map<int, char> Umap = {{1, 'a'}, {2, 'b'}};

	// Access (key)
	cout << Umap[1] << endl;
	cout << Umap[2] << endl;

	// Update
	Umap[1] = 'c';

	for (auto& e : Umap)
		cout << e.first << "-" << e.second << "\n";
	cout << endl;

	// Find
	auto result = Umap.find(2);
	if (result != Umap.end())
		cout << "Found " << result->first << "-" << result->second << "\n";
	else
		cout << "Not Found";
	return 0;
}