#include <iostream>
using namespace std;

struct Array
{
    int A[20];
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

struct Array* Merge(struct Array *arr1, struct Array *arr2)  //Merging sorted arrays
{
    int i=0, j=0, k=0;
    struct Array *arr3 = new Array;

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] <= arr2->A[j])
            arr3->A[k++] = arr1->A[i++];

        else
            arr3->A[k++] = arr2->A[j++];
    }
    while(j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    while(i < arr1->length)
        arr3->A[k++] = arr1->A[i++];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;

    return arr3;
}

int main()
{
    struct Array arr1 = {1,2,7,11,13,14,19},10,7};
    struct Array arr2 = {3,5,7,10,13,17,19},10,7};

    struct Array *arr3 = Merge(&arr1, &arr2);
    Display(*arr3);
    return 0;
}
