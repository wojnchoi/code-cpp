#include<iostream>

using namespace std;

void solve(int change, int *coin) {
    for(int i=0; i<4;i++) {
        int result = change/coin[i];
        change %= coin[i];
        cout<<coin[i]<<": "<<result<<endl;
    }
}
int main() {
    int coin[4] = {500,100,50,10};
    int change;
    cout<<"change amount: ";
    cin>>change;

    solve(change,coin);
    return 0;
}