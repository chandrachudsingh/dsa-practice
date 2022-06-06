#include <iostream>
using namespace std;

void perm(char s[], int l, int h)
{
    if(l == h)
        cout << s << endl;
    else
    {
        for(int i=l; i<=h; i++)
        {
            swap(s[l],s[i]);
            perm (s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main()
{
    char str[] = {'A','B','C'};
    perm(str, 0, 2);
    return 0;
}
