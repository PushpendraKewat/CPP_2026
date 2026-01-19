#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}