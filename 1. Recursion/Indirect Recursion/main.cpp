#include <iostream>
using namespace std;

void funB(int);

void funA(int n)
{
    if(n>0)
    {
        cout<<n<<'\t';
        funB(n-1);
    }
}

void funB(int n)
{
    if(n>1)
    {
        cout<<n<<'\t';
        funA(n/2);
    }
}

int main()
{
    funA(11);
    return 0;
}
