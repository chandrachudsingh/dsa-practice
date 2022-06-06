#include <iostream>
using namespace std;

double recur_e(int x, int n)
{
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + ((double)x/n) * s;   //as both x and n are int
    return recur_e(x, n-1);
}

double iter_e(int x, int n)
{
    double s = 1;
    for(; n>0; n--)
        s = 1 + ((double)x/n) * s;
    return s;
}

int main()
{
    cout << recur_e(5, 20);
//    cout << iter_e(5, 20);
    return 0;
}
