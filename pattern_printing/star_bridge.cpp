#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin >> n;

    for(int i = n; i >= 1; i--){
        // left stars
        for(int j = 1; j <= i; j++)
            cout << "*";

        // middle spaces
        for(int k = 1; k <= 2*(n-i)-1; k++)
            cout << " ";

        // right stars
        for(int l = 1; l <= i; l++)
            cout << "*";

        cout << endl;
    }
    return 0;
}
