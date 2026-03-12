#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"enter n :";
    cin>>n;
    int c =0;
    for(int i =2;i*i<=n;i*=i){
        c++;
    }

}