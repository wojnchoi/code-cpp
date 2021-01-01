#include<iostream>

using namespace std;
int main()
{
    int arr[10] = {1, 3, 5, 7, 9};
    int item = 151, k = 2, n = 5;
    int j = n;
    cout<<"The original array elements are : \n";
    for(int i=0;i<n;i++)
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
    
    n += 1;

    while(j >= k) {
        arr[j+1] = arr[j];
        j -= 1;
    }

    arr[k] = item;

    cout<<"The array elements after insertion\n";

    for(int i=0;i<n;i++)
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;

        return 0;
}