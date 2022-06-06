#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void FindPair(int arr[], int n, int k)
{
    cout << "Pair with sum " << k << " are:\n";
    for(int i=0, j=n-1; i<j;)
    {
        if(arr[i]+arr[j] == k)
        {
            cout << "(" << arr[i] << "," << arr[j] << ")\n";
            i++;
            j--;
        }
        else if(arr[i]+arr[j] > k)
            j--;
        else
            i++;
    }
}

void FindPair_Hashing(int arr[], int n, int k)
{
    int x = arr[n-1]+1;
    int H[x] = {0};

    cout << "Pair with sum " << k << " are:\n";
    for(int i=0; i<n; i++)
    {
        if(H[k-arr[i]] != 0 && arr[i] <= k)
            cout << "(" << arr[i] << "," << k-arr[i] << ")\n";
        H[arr[i]] = 1;
    }
}

int main()
{
    int arr[] = {1,3,4,5,6,7,8,9,10,12,14};

    FindPair(arr, 10, 12);
//    FindPair_Hashing(arr, 10, 12);
    return 0;
}
