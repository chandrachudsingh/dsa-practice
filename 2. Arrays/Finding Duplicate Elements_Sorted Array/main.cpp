#include <iostream>
using namespace std;

void FindDuplicate(int arr[], int n)
{
    int lastduplicate = 0;
    cout << "Duplicate numbers are:\t";
    for(int i=0; i<n-1; i++)
    {
        if(arr[i] == arr[i+1] && lastduplicate != arr[i])
        {
            lastduplicate = arr[i];
            cout << lastduplicate << "\t";
        }
    }
    cout << "\n";
}

void FindDuplicate_Hashing(int arr[], int n)    // Finding Duplicate using Hash table
{
    int H[arr[n-1]+1] = {0};
    cout << "Duplicate numbers are:\t";
    for(int i=0; i<n; i++)
    {
        H[arr[i]]++;
    }

    for(int i=0; i<=arr[n-1]; i++)
    {
        if(H[i] > 1)
            cout << i << "\t";
    }
    cout << "\n";
}

void CountDuplicate(int arr[], int n)
{
    for(int i=0, j=0; i<n-1; i++)
    {
        if(arr[i] == arr[i+1])
        {
            j = i+1;
            while(arr[j] == arr[i])
                j++;
            cout << arr[i] << " is appearing " << j-i << " times.\n";
            i = j-1;
        }
    }
}

int main()
{
    int arr[] = {3,6,8,8,10,12,15,15,15,20};

//    FindDuplicate(arr, 10);
    FindDuplicate_Hashing(arr, 10);
    CountDuplicate(arr, 10);
    return 0;
}
