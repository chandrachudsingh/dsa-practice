#include <iostream>
using namespace std;

void Find1(int arr[], int n)    //Finding Missing element for first n natural no's
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    int S = (n+1)*(n+2)/2;
    cout << "Missing Element is " << S - sum << endl;
}

void Find2(int arr[], int n)    //Finding Missing element numbers not starting from 0
{
    int diff = arr[0] - 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]-i != diff)
        {
            cout << "Missing element is " << i+diff << endl;
            break;
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,8,9,10,11,12};
    Find1(arr, 11);
    int arr2[] = {6,7,8,9,10,12,13,15,16,17};
    Find2(arr2, 10);

    return 0;
}
