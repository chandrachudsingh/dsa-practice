#include <iostream>
using namespace std;

double recur_e(int x, int n)
{
    static double p=1, f=1;
    double r;
    if(n == 0)
        return 1;
    else
    {
        r = recur_e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}

double iter_e(int x, int n)
{
    double s = 1, num = 1, den = 1;
    for(int i=1; i<=n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main()
{
    cout << recur_e(5, 10);
//    cout << iter_e(5, 10);
    return 0;
}
