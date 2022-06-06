#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        A = new int[size];
        size = 10;
        length = 0;
    }

    Array(int size)
    {
        A = new int[size];
        this->size = size;
        length = 0;
    }

    ~Array()
    {
        delete []A;
    }

void Display();
void Append(int x);
void Insert(int x, int index);
void Delete(int x);
int Search(int x);
int Get(int index);
void Set(int x, int index);
int Max();
int Min();
void Reverse();
void Shift(int shift);
void Rotate(int shift);
};

void Array::Display()
{
    cout << "Elements are:\n";
    for(int i=0; i<length; i++)
        cout << A[i] << ' ';
    cout << "\n";
}

void Array::Append(int x)
{
    if(length < size)
        A[length++] = x;
}

void Array::Insert(int x, int index)
{
    if (index >= 0 && index < length)
    {
        for(int i=length; i>index; i--)
            A[i] = A[i-1];
        A[index] = x;
    }
    if(length < size)
        length++;
}

void Array::Delete(int index)
{
    if(index >= 0 && index < length)
    {
        for(int i=index; i<length-1; i++)
            A[i] = A[i+1];
        length--;
    }
}

int Array::Search(int x)
{
    for(int i=0; i<length; i++)
    {
        if(A[i] == x)
            return i;
    }
    return -1;
}

int Array::Get(int index)
{
    if(index >= 0 && index <= length)
        return A[index];
}

void Array::Set(int x, int index)
{
    if(index >= 0 && index <= length)
        A[index] = x;
}

int Array::Max()
{
    int max = A[0];
    for(int i=1; i<length; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    for(int i=1; i<length; i++)
    {
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

void Array::Reverse()
{
    for(int i=0; i<length/2; i++)
    {
        int temp = A[i];
        A[i] = A[length-i-1];
        A[length-i-1] = temp;
    }
}

void Array::Shift(int shift)
{
    if(shift<0)
    {
        for(int i=0; i<length-1; i++)
            A[i] = A[i+1];
        A[length-1] = 0;
    }
    else
    {
        for(int i=length-1; i>0; i--)
            A[i] = A[i-1];
        A[0] = 0;
    }
}

void Array::Rotate(int shift)
{
    if(shift<0)
    {
        int x = A[0];
        for(int i=0; i<length-1; i++)
            A[i] = A[i+1];
        A[length-1] = x;
    }
    else
    {
        int x = A[length-1];
        for(int i=length-1; i>0; i--)
            A[i] = A[i-1];
        A[0] = x;
    }
}

int main()
{
    Array *arr;
    int size;

    cout << "Enter size of the array: ";
    cin >> size;
    arr = new Array(size);

    while(1)
    {
        int opt;
        cout << "Enter a choice for continuing:\n1-Display\n2-Append\n3-Insert at an index\n4-Delete an element\n"
            << "5-Search an element\n6-Get element at an index\n7-Set element at an index\n8-Max of array\n"
            << "9-Min of array\n10-Reverse the array\n11-Shift array elements to right or left\n"
            << "12-Rotate array elements to right or left\nAny other number-exit\n";
        cin >> opt;

        switch(opt)
        {
            int x, index, shift, result;
            case 1:
                arr->Display();
                break;
            case 2:
                cout << "Enter an element to append: ";
                cin >> x;
                arr->Append(x);
                break;
            case 3:
                cout << "Enter an element and index at where to insert the element: ";
                cin >> x >> index;
                arr->Insert(x, index);
                break;
            case 4:
                cout << "Enter the index of an element to delete: ";
                cin >> index;
                arr->Delete(index);
                break;
            case 5:
                cout << "Enter an element to search: ";
                cin >> x;
                result = arr->Search(x);
                if(result != -1)
                    cout << "Element found at index " << result << "\n";
                else
                    cout << "Element not found!" << "\n";
                break;
            case 6:
                cout << "Enter an index to get element at that index: ";
                cin >> index;
                result = arr->Get(index);
                cout << "Element at given index : " << result << "\n";
                break;
            case 7:
                cout << "Enter an element and index to set that element at that index: ";
                cin >> x >> index;
                arr->Set(x, index);
                break;
            case 8:
                result = arr->Max();
                cout << "Max element is " << result << "\n";
                break;
            case 9:
                result = arr->Min();
                cout << "Min element is " << result << "\n";
                break;
            case 10:
                arr->Reverse();
                break;
            case 11:
                cout << "Enter -1 to left shift and 1 to right shift: ";
                cin >> shift;
                arr->Shift(shift);
                break;
            case 12:
                cout << "Enter -1 to left rotate and 1 to right rotate: ";
                cin >> shift;
                arr->Rotate(shift);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
