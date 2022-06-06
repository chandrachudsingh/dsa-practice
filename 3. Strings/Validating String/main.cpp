#include <iostream>
using namespace std;

bool validate(char *s)
{
    for(int i=0; s[i]!='\0'; i++)
    {
        if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=48 && s[i]<=57))
            return false;
    }
    return true;
}

int main()
{
    char *str = "ccsc@2560";
    if(validate(str))
        cout << "Valid String";
    else
        cout << "Invalid String";
    return 0;
}
