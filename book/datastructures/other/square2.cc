#include<iostream>
#include<cstdlib>

using namespace std;

int pow(int a, int b)
{
    int pow = 1;
    for(int i=0; i<b;i++)
        pow *= a;

    return pow;
}
int main()
{
    int arr[10];
       for(int i=0;i<10;i++)
            arr[i] = pow(2,i);

    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}