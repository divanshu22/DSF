#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void ispower(int n)
{
    double k;
    k = log(n)/log(4);
    if(floor(k) == ceil(k))
        cout<<"Number is a power of 4";
    else
        cout<<"Nah";


}


int main()
{
    int n;
    cout<<"Enter the number you want to check : ";
    cin>>n;
    ispower(n);


    return 0;
}
