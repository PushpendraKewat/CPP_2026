#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        int p = 1;
        for(int k=1;k<=2*i-1;k++){
            if(k<=i){
                cout<<p;
                p++;
            }else{
                p-=2;
                cout<<p;
                p++;
               
            }
        }
        cout<<endl;
    }
    return 0;
}