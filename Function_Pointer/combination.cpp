#include<iostream>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;

int fact(int n){
    int f = 1;
    for(int i=1;i<=n;i++){
        f = f*i;
    }
    return f;
}

int main(){
    int n,r;
    cout<<"Enter N & R :";
    cin>>n>>r;
    int a = fact(n); // a = n!
    int b = fact(r); // b = r!
    int c = fact(n-r); //c = n-r!
    cout<<a/(b*c);
    return 0;
}