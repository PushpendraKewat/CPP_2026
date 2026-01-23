#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void printTriangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int a,b,c;
    cout<<"Enter three numbers : ";
    cin>>a>>b>>c;

    printTriangle(a);
    printTriangle(b);
    printTriangle(c);

    return 0;
}
