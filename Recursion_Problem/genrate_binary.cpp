#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void genrate_binary(string s, int n ){
    if(s.length()==n){
        cout<<s<<endl;
        return;
    }
    
    genrate_binary(s+'0',n);
    genrate_binary(s+'1',n);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    genrate_binary("",n);
    return 0;
}