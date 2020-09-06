#include<bits/stdc++.h>
#include<math.h>
#include<string.h>

using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int h = 0;
    int n = str.length() - 1;
    while(n>h)
    {
        if(str[h++]!=str[n--])
        {
            cout<<"%s is Not palindrome",str;

        }
    break;
    }
    cout<<"%s It is palindrome",str;

    return 0;
}
