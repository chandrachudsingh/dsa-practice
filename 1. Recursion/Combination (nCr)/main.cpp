#include <iostream>
using namespace std;

int fact(int);

int recur_nCr(int n, int r)
{
    if(r==0 || r==n)
        return 1;
    else
        return recur_nCr(n-1,r-1) + recur_nCr(n-1,r);
}

int iter_nCr(int n, int r)
{
    int num, den;
    if(r==0 || r==n)
        return 1;

    num = fact(n);
    den = fact(r) * fact(n-r);

    return num/den;
}

int fact(int n)
{
    if(n==0)
        return 1;
    return fact(n-1)*n;
}

int main()
{
    cout << recur_nCr(10,5);
//    cout << iter_nCr(10,5);
    return 0;
}
