#include<iostream>

using namespace std;

int factorialIterative(int n) {
    int result = 1;
    for(int i = 1; i<=n; i++) {
        result *= i;
    }
    return result;
}
int factorialRecursive(int n) {
    if(n <= 1) return 1;
    return n * factorialRecursive(n-1);
}
int main() {
    cout<<"iterative: "<< factorialIterative(5) << "\n";
    cout<<"recursive: "<< factorialRecursive(5) << "\n";
    return 0;
}