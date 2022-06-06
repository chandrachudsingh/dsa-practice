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

struct Array* Union(struct Array *arr1, struct Array *arr2)  //Merging sorted arrays
{
    int i=0, j=0, k=0;
    struct Array *arr3 = new Array;

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    while(j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    while(i < arr1->length)
        arr3->A[k++] = arr1->A[i++];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2)  //Merging sorted arrays
{
    int i=0, j=0, k=0;
    struct Array *arr3 = new Array;

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Diff(struct Array *arr1, struct Array *arr2)  //Merging sorted arrays
{
    int i=0, j=0, k=0;
    struct Array *arr3 = new Array;

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            i++;
            j++;
        }
    }
    while(j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    while(i < arr1->length)
        arr3->A[k++] = arr1->A[i++];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,6,7,15,20},10,5};
    struct Array *arr3;

    arr3 = Union(&arr1, &arr2);
//    arr3 = Intersection(&arr1, &arr2);
//    arr3 = Diff(&arr1, &arr2);
    Display(*arr3);
    return 0;
}
