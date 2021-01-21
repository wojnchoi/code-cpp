#include<iostream>
using namespace std;

int main() {
    int N, K,cnt = 0;
    cin>>N>>K;

    while(N != 1) {
        if(N%K == 0) {
            N /= K;
            cnt++;
        } else {
            N--;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}