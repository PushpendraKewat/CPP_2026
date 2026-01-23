#include<iostream>
using std::cout;
using std::cin;
using std::endl;

long long fact(int n){
    long long f = 1;
    for(int i = 1; i <= n; i++){
        f = f * i;
    }
    return f;
}

int main(){
    int n, r;
    cout << "Enter N & R : ";
    cin >> n >> r;

    if(r > n || n < 0 || r < 0){
        cout << "Invalid input";
        return 0;
    }

    long long nPr = fact(n) / fact(n - r);
    long long nCr = fact(n) / (fact(r) * fact(n - r));

    cout << "Permutation (nPr) = " << nPr << endl;
    cout << "Combination (nCr) = " << nCr << endl;

    return 0;
}
