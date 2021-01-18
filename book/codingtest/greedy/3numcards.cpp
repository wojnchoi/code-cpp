#include<iostream>
using namespace std;

int main() {
    int M, N;
    cin>>M>>N;
    int arr[M][N];

    for(int i=0; i<M;i++) {
        for(int j=0;j<N;j++)
            cin>>arr[i][j];
    }
    int big = 10001, result = 0;
    for(int i=0; i<M;i++) {
        for(int j=0; j<N; j++) {
            if(big >= arr[i][j])
                big = arr[i][j];
        }
        if(result <= big)
            result = big;
        big = 10001;
    }
    cout<<result<<endl;
    return 0;
}