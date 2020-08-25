#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void count1(int arr[], int n)
{
    int number=0;
    for(int i = 1; i < n; i++){
        int j=0;
        for(j = 0; j < i; j++)
           if(arr[i]==arr[j])
            break;

            if(i==j)
                number++;
    }
    number = number + 1;
    int number1 = number * number;
    cout<< number << endl;
    cout << number1;
}




int main()
{
    int n,arr[10];
    cout<<"Size of array : ";
    cin>>n;
    cout<<"Enter array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    count1(arr,n);

return 0;

}
