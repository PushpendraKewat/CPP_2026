#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// void sum1toN(int sum, int n){
//     if(n==0){
//         cout<<sum<<endl;
//         return;
//     }
//     sum1toN(sum+n,n-1);
// }

int sum1toN(int n){
    if(n==0) return 0;
    return n + sum1toN(n-1);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    // sum1toN(0,n);
    cout<<sum1toN(n);
    return 0;
}