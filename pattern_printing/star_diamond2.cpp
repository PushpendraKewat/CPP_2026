#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout << "Enter the number (odd): ";
    cin >> n;

    int space = n-1;
    int star = 1;

    for(int i = 1; i <= 2*n-1; i++){
        //  spaces
        for(int j = 1; j <= space; j++){
            cout << " ";
        }
        if(i<n) space--;
        else space++;
        // stars
        for(int k = 1; k <= star; k++){
            cout << "*";
        }
        if(i<n) star +=2;
        else star-=2;
        cout << endl;
    }

    return 0;
}
