#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    // method 1
    // for(int i = 1; i <= n; i++){
    //     // spaces
    //     for(int j = 1; j <= n - i; j++){
    //     cout << " ";
    //     }
    //     // stars
    //     for(int k = 1; k <= n; k++){
    //     cout << "*";
    //     }
    //     cout << endl;
    // }


    //method 2
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=2*n - 1; j++){
            if(j >= n - i + 1 && j <= n - i + n)
            cout << "*";
            else
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
