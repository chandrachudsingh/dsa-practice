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

struct Array* Union(struct Array arr1, struct Array arr2)
{
    int k=0;
    struct Array *arr3 = new Array;

    for(int i=0; i<arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    int flag;
    for(int j=0; j<arr2.length; j++)
    {
        flag = 0;
        for(int i=0; i<arr1.length; i++)
        {
            if(arr2.A[j] == arr1.A[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag != 1)
            arr3->A[k++] = arr2.A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Intersection(struct Array arr1, struct Array arr2)
{
    int k=0;
    struct Array *arr3 = new Array;

    for(int j=0; j<arr2.length; j++)
    {
        for(int i=0; i<arr1.length; i++)
        {
            if(arr2.A[j] == arr1.A[i])
            {
                arr3->A[k++] = arr2.A[j];
                break;
            }
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct Array* Diff(struct Array arr1, struct Array arr2)
{
    int k=0;
    struct Array *arr3 = new Array;

    int flag = 0;
    for(int i=0; i<arr1.length; i++)
    {

        for(int j=0; j<arr2.length; j++)
        {
            if(arr1.A[i] == arr2.A[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            arr3->A[k++] = arr1.A[i];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    struct Array arr1 = {{3,5,10,4,6},10,5};
    struct Array arr2 = {{12,4,7,2,5},10,5};
    struct Array *arr3;

//    arr3 = Union(arr1, arr2);
//    arr3 = Intersection(arr1, arr2);
    arr3 = Diff(arr1, arr2);
    Display(*arr3);

    return 0;
}
