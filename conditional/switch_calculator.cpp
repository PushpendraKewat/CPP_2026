#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    float a,b;
    cout<<"Enter first number:";
    cin>>a;
    cout<<"Enter second number:";
    cin>>b;
    char op;
    cout<<"Enter operator (+,-,*,/) :";
    cin>>op;
    switch(op){
        case '+':
            cout<<"Sum is: "<<a+b;
            break;
        case '-':
            cout<<"Difference is: "<<a-b;
            break;
        case '*':
            cout<<"Product is: "<<a*b;
            break;
        case '/':
            if(b != 0){
                cout<<"Quotient is: "<<a/b;
            } else {
                cout<<"Error: Division by zero";
            }
            break;
        default:
            cout<<"Invalid Operator";
    }
    return 0;
}