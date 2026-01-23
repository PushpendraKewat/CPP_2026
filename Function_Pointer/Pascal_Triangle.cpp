#include<iostream>
using std::cout;
using std::cin;
using std::endl;

long long fact(int n){
    long long f = 1;
    for(int i = 1; i <= n; i++){
        f *= i;
    }
    return f;
}

long long combination(int n, int r){
    return fact(n) / (fact(r) * fact(n - r));
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            cout << combination(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
