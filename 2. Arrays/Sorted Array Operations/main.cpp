#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout << "Elements are:\n";
    for(int i=0; i<arr.length; i++)
        cout << arr.A[i] << ' ';
    cout << "\n";
}

void InsertSorted(struct Array *arr, int x)    //Insert element into sorted array
{
    int i = arr->length - 1;
    if(arr->length == arr->size)
        return;
    while(i >= 0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(struct Array arr)  //to check if array is sorted
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length -1;

    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>0)
            j--;
        if(i<j)
            swap(arr->A[i],arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{1,2,7,9,13,15,19},10,7};
    int x;
    cout << "Enter an element to insert into sorted array: ";
    cin >> x;

    InsertSorted(&arr, x);
    Display(arr);

    struct Array arr2 = {{1,2,7,5,13,11,19},10,7};
    int result = isSorted(arr2);
    if(result != 0)
        cout << "Array is sorted\n";
    else
        cout << "Array not sorted\n";

    struct Array arr3 = {{1,-2,7,-5,-13,11,-19},10,7};
    Rearrange(&arr3);
    Display(arr3);

    return 0;
}
