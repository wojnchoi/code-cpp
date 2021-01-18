#include<iostream>

using namespace std;

void solve(int *arr,int size, int add, int law) {
    int big = 0,small=0,result =0;
    for(int i=0;i<size;i++) {
        if(big < arr[i]) {
            small = big;
            big=arr[i];
        } else if(arr[i] > small)
            small = arr[i];
    }
    int j =0;
    for(int i=0;i<add;i++) {
        if(j != law) {
            result += big;
            j++;
        } else if(j == law) {
            result+=small;
            j = 0;
        }
    }
    printf("%d\n",result);
}
int main() {
    int N,M,K;
    cout<<"<size> <add> <law>: ";
    cin>>N>>M>>K;
    int arr[N];
    cout<<N<<" values: ";
    for(int i=0; i<N;i++) {
        cin>>arr[i];
    }
    if(K <= M)
        solve(arr,N,M,K);
    else 
        cout<<"law is bigger than add"<<endl;
    return 0;
}