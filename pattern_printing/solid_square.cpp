#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}