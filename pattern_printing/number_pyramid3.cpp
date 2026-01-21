#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    int mid = n;
    for(int i=1;i<=n;i++){
        int num =1;
        for(int j=1;j<=2*n;j++){
            if(j>= mid-i+1 && j<=mid+i-1){
                cout<<num;
                num++;
            }
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}