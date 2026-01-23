#include<iostream>
using std::cout;
using std::cin;
using std::endl;


int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for(int i = 0; i <= n; i++){
        int curr = 1;
        for(int j = 0; j <= i; j++){
            cout<<curr<<" ";
            int next = curr*(i-j)/(j+1);
            curr = next;
        }
        cout << endl;
    }
    return 0;
}
