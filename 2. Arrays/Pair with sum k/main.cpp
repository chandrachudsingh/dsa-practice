#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void FindPair(int arr[], int n, int k)
{
    cout << "Pair with sum " << k << " are:\n";
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j] == k)
                cout << "(" << arr[i] << "," << arr[j] << ")\n";
        }
    }
}

void FindPair_Hashing(int arr[], int n, int k)
{
    int x = *max_element(arr,arr+n)+1;
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
    int arr[] = {6,3,8,10,16,7,5,2,9,14};

//    FindPair(arr, 10, 12);
    FindPair_Hashing(arr, 10, 12);
    return 0;
}
