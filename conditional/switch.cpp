#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int days;
    cout<<"Enter the number of days (1 to 7):";
    cin>>days;
    switch(days){
        case 1:
            cout<<"Monday";
            break;
        case 2:
            cout<<"Tuesday";
            break;
        case 3:
            cout<<"Wednesday";
            break;
        case 4:
            cout<<"Thursday";
            break;
        case 5:
            cout<<"Friday";
            break;
        case 6:
            cout<<"Saturday";
            break;
        case 7:
            cout<<"Sunday";
            break;
        default:
            cout<<"Invalid Input";
    }
    return 0;
}