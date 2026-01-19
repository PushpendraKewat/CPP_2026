#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter number of rows(only odd): ";
    cin>>n;
    // n has to be odd
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i==j) || (i+j==n+1)){
                cout<<"*";
            }
            else {
                cout<<" ";
            }   
        }
        cout<<endl;
    }
    return 0;
}