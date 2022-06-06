#include <iostream>
using namespace std;

void Reverse(char A[])
{
    int j;
    for(j=0; A[j+1]!='\0'; j++){}
    for(int i=0; i<j; i++,j--)
        swap(A[i],A[j]);
    cout << A;
}

int main()
{
    char A[] = "python";
    Reverse(A);
    return 0;
}
