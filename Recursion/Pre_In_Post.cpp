#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void pip(int n){
    if(n==0) return;
    cout<<"Pre "<<n<<endl;
    pip(n-1);
    cout<<"In "<<n<<endl;
    pip(n-1);
    cout<<"Post "<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter n for Pre In Post :";
    cin>>n;
    pip(n);
    return 0;
}
