#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int stars = 1;   // extra variable
    int spaces = n-1;

    for(int i = 1; i <= n; i++){
        // spaces
        for(int j = 1; j <=spaces; j++){
            cout << " ";
        }
        spaces--;
        // stars
        for(int k = 1; k <= stars; k++){
            cout << "*";
        }

        cout << endl;
        stars += 2;  // update for next row
    }
    return 0;
}
