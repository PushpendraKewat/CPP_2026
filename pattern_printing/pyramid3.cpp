#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number :";
    cin >> n;

    int mid = n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2*n; j++){
            if(j >= mid - i + 1 && j <= mid + i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
