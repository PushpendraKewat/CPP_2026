#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    print(n);
    return 0;
}