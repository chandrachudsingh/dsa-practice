#include <iostream>
using namespace std;

int Binary_Search(int A[], int l, int h, int key)
{
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int RBinary_Search(int A[], int l, int h, int key)
{
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return RBinary_Search(A, l, mid-1, key);
        else
            return RBinary_Search(A, mid+1, h, key);
    }
    return -1;
}

int main()
{
    int arr[] = {10,20,30,40,50,60,70};
    int key, index;

    cout << "Enter an element to search: ";
    cin >> key;

//    index = Binary_Search(arr, 0, 6, key);
    index = RBinary_Search(arr, 0, 6, key);
    if(index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";

    return 0;
}
