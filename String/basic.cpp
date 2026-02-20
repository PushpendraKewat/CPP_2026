#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    // char str[] = {'a','b','c','d','e'};
    // for(int i=0;i<5;i++){
    //     cout<<str[i]<<" ";
    // }
    // cout<<endl;
    string str;
    cout<<"Enter the string :";
    getline(cin,str);
    cout<<str;
    return 0;
}