#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    int star = 1, space = n-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
        space--;
        for(int k=1;k<=star;k++){
            cout<<k;
        }
        star +=2;
        cout<<endl;
    }
    return 0;
}