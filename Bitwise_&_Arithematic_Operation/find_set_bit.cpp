#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// int count_set_bits(int n){

//     return __builtin_popcount(n);
// }

int countset_bits(int n){
    int count = 0;
    while(n>0){
        count++;
        n = (n&(n-1));
    }
    return count;
}

int main(){
    // cout << count_set_bits(64) << endl;
    int n;
    cout<<"Enter n :";
    cin>>n;
    cout<<countset_bits(n);
    return 0;
}