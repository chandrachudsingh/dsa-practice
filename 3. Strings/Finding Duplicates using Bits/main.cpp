#include <iostream>
using namespace std;

int main()
{
    char A[] = "findinnnng";
    //As for hashing we take array size 26 but for bits 26
    //is not possible, so we take 32 bits i.e. 4 bytes(long int)
    long int h1 = 0, h2 = 0, x = 0;

    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);
        if ((x & h1) > 0)
            h2 = (x & h1) | h2;
        else
            h1 = x | h1;
    }

    x = 1;
    int count = 0;
    while (count >= 0 && count <= 25)
    {
        if ((h2 & x) > 0)
            cout << (char)(count + 97) << " is duplicate." << "\n";
        x = x << 1;
        count++;
    }

    return 0;
}
