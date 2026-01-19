#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int num=1;
        for(int j=1;j<=i;j++){
           cout<<num<<" ";
            num+=2;
        }
        cout<<endl;
    }
    return 0;
}