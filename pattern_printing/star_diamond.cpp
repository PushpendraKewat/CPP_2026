#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout << "Enter the number (odd): ";
    cin >> n;

    int space = n / 2;
    int star = 1;

    for(int i = 1; i <= n; i++){
        //  spaces
        for(int j = 1; j <= space; j++){
            cout << " ";
        }

        // stars
        for(int k = 1; k <= star; k++){
            cout << "*";
        }

        cout << endl;

        // update space & star
        if(i <= n/2){
            space--;
            star += 2;
        } else {
            space++;
            star -= 2;
        }
    }

    return 0;
}
