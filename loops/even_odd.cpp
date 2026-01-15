#include<iostream>

using std::cout;
using std::endl;

int main(){
    for(int i=1;i<=100;i++){
        if(i%2==0){
            cout<<i<<" is Even"<<endl;
        } else {
            cout<<i<<" is Odd"<<endl;
        }
    }
    return 0;
}