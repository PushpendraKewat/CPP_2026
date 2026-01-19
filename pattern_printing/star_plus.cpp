#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter number of rows(only odd): ";
    cin>>n;
    // n has to be odd
    int mid = (n/2)+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==mid || j==mid){
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}