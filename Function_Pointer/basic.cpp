#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void greet(int a){
    if(a <= 0){
        cout << "Please enter a positive number" << endl;
        return;
    }
    for(int i=1;i<=a;i++){
        cout<<i<<". Hey Ram" << endl;
        cout<<"   Har Har Mahadev" << endl;
    }

}

int main(){
    int n;
    cout<<"Enter the number you want greet :";
    cin>>n;
    greet(n);
    return 0;
}
