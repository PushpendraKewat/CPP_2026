#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// int hcf(int a, int b){
//     for(int i = std::min(a, b); i >= 2; i--){
//         if(a % i == 0 && b % i == 0) return i;
//     }
//     return 1;
// }

// int hcf(int a, int b){
//     while(b != 0){
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

int rhcf(int a, int b){
    if(b == 0) return a;
    return rhcf(b, a % b);
}

int main(){
    int a, b;
    cout << "Enter the value of a & b : ";
    cin >> a >> b;

    // cout << "HCF = " << hcf(a, b);
    // cout<<hcf(a,b);
    cout<<rhcf(a,b);

    return 0;
}