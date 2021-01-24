#include<bits/stdc++.h>

using namespace std;

/* stack
stack<int> s;

int main() {
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(7);
    s.pop();
    s.push(1);
    s.pop();

    while(!s.empty()) {
        cout<< s.top() << ' ';
        s.pop();
    }
    return 0;
}
*/

/* queue
queue<int> q;

int main() {
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(7);
    q.pop();
    q.push(1);
    q.pop();

    while(!q.empty()) {
        cout<< q.front() << " ";
        q.pop();
    }
    cout<<'\n';
    return 0;
}
*/

void recursiveFunction(int i) {
    if(i == 100) return;
    cout<<i<<" recursive calling "<<i+1<<".\n";
    recursiveFunction(i+1);
    cout<<i<<" recursive ending \n";
}

int main(void) {
    recursiveFunction(0);
}