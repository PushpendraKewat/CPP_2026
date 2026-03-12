#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void print(int n){
    if(n==0) return;
    cout<<n<<endl;
    print(n-1);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    print(n);
    return 0;
}