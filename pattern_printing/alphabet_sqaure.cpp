#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    /*111
      222
      333 */
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<rows; j++){
    //         cout<<i+1<<" ";
    //     }
    //     cout<<endl;
    // }

    // /*123
    //   123
    //   123 */
    
    for(int i=0; i<rows; i++){
         char ch = 'A';
        for(int j=0; j<rows; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }

    return 0;
}