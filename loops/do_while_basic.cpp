#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    /* this program demonstate basic of do while loop
    1. do while loop is executed at least once even if the condition is false */
    int i=11;
    do{
        cout<<i<<" : ram ram"<<endl;
        i++;
    }while(i<=10);
    return 0;
}