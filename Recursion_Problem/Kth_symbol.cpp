#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int kth(int n, int k){
    // base case
    if(n == 1) return 0;

    // if k is even → flip
    if(k % 2 == 0){
        return 1 - kth(n - 1, k / 2);
    }
    // if k is odd → same
    else{
        return kth(n - 1, k / 2 + 1);
    }
}

int main(){
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << kth(n, k);

    return 0;
}