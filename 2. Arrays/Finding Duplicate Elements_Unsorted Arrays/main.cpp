#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void FindDuplicate(int arr[], int n)
{
    cout << "Duplicate numbers are:\n";
    for(int i=0; i<n; i++)
    {
        if(arr[i] != -1)
        {
            int count = 1;
            for(int j=i+1; j<n; j++)
            {
                if(arr[i] == arr[j])
                {
                    arr[j] = -1;
                    count++;
                }
            }
            cout << arr[i] << " has appeared " << count << " times.\n";
        }
    }
    cout << "\n";
}

void FindDuplicate_Hashing(int arr[], int n)    // Finding Duplicate using Hash table
{
    int x = *max_element(arr,arr+n)+1;
    int H[x] = {0};
    cout << "Duplicate numbers are:\n";
    for(int i=0; i<n; i++)
        H[arr[i]]++;

    for(int i=1; i<x; i++)
    {
        if(H[i] > 0)
            cout << i << " has appeared " << H[i] << " times.\n";
    }

    cout << "\n";
}

int main()
{
    int arr[] = {8,3,6,4,6,5,6,8,2,7};

//    FindDuplicate(arr, 10);
    FindDuplicate_Hashing(arr, 10);
    return 0;
}
