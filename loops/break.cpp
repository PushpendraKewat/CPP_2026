#include<iostream>

using std::cout;
using std::cin;
using std::endl;   

int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    // break statement exit the loop when the condition is met
    for(int i=1;i<=n;i++){
        cout<<"Ram Ram"<<endl;
        if(i==5){
            break;
        }
    }
    return 0;
}