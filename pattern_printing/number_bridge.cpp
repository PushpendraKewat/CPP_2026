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

    // first line number
    for(int i=1;i<=2*n-1;i++){
        cout<<i;
    }
    cout<<endl;
    // 1st half number 
    for(int i=1;i<=m;i++){
           int a = 1;
        for(int j=1;j<=m+1-i;j++){
            cout<<a;
            a++;
        }
        // space 
        for(int k=1;k<=space;k++){
            cout<<" ";
            a++;
        }
        space +=2;
        // 2nd half number
     
        for(int l=m;l>=i;l--){
            cout<<a;
            a++;
        }

        cout<<endl;
    }
    return 0;
}