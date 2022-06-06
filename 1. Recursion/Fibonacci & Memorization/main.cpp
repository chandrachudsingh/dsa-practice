#include <iostream>
using namespace std;

int F[10];

int recur_fib(int n)    // using memorization
{
    if(n<=1)
        return n;

    for(int i=2; i<=n; i++)
    {
        if(F[n-2] == -1)
            F[n-2] = recur_fib(n-2);
        if(F[n-1] == -1)
            F[n-1] = recur_fib(n-1);
    }
    return F[n-2] + F[n-1];
}

int iter_fib(int n)
{
    int t1 = 0, t2 = 1, s;
    if(n<=1)
        return n;

    for(int i=2; i<=n; i++)
    {
        s = t1+t2;
        t1 = t2;
        t2 = s;
    }
    return s;
}

int main()
{
    for(int i=0; i<10; i++)
        F[i] = -1;
    cout << recur_fib(5);
//    cout << iter_fib(10);
    return 0;
}
