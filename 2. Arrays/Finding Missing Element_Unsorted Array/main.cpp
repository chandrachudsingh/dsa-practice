#include <iostream>
using namespace std;

void Find_Missing(int arr[], int n)    //Finding Missing element in unsorted array having n natural no's
{
    int l = min(arr), h = max(arr);
    int H[h - l + 1] = {0}; // Hash table or Bitset
    for (int i = 0; i < n; i++)
        H[arr[i]]++;

    cout << "Missing elements are:\t";
    for (int i = l; i <= h; i++)
    {
        if (H[i] == 0)
            cout << i << '\t';
    }
}

int main()
{
    int arr[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    Find_Missing(arr, 11);

    return 0;
}
