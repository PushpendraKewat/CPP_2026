#include<iostream>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;

void function(int a,int b){
    cout<<"minimum of a & b is :"<<std::min(a,b)<<endl;
    cout<<"maximum of a & b is :"<<std::max(a,b)<<endl;
}

int main(){
    int a,b;
    cout<<"Enter two number :";
    cin>>a>>b;
    function(a,b);
    return 0;
}