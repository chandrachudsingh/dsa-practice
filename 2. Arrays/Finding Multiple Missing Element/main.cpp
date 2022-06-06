#include <iostream>
using namespace std;

void Find_Missing(int arr[], int n)    //Finding multiple Missing element numbers not starting from 0
{
    int diff = arr[0] - 0;
    cout << "Missing elements are:\t";
    for(int i=0; i<n; i++)
    {
        if(arr[i]-i != diff)
        {
            while(diff < arr[i] - i)
            {
                cout << i+diff << '\t';
                diff++;
            }
        }
    }
}

int main()
{
    int arr[] = {6,7,8,9,10,12,15,16,17,18};
    Find_Missing(arr, 10);

    return 0;
}
