#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    int m = n-1; // new line
    int space =1;
    for(int i=1;i<=2*n-1;i++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m+1-i;j++){
            cout<<"*";
        }
        for(int k=1;k<=space;k++){
            cout<<" ";
        }
        space +=2;
        for(int l=m;l>=i;l--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}