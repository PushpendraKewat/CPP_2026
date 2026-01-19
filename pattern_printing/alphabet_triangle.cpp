#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        // char ch = (int)i+64;
        for(int j=1;j<=i;j++){
            char ch = (int)j+64;
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}