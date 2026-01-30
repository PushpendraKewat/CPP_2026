#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    // method 1
    // int arr[5]; // array declaration
    // arr[0] = 1; // array intialization of single element
    // arr[1] = 2;
    // arr[2] = 3;
    // arr[3] = 4;
    // arr[4] = 5;

    // cout<<arr[0]<<endl; // printing individual element
    // cout<<arr[1]<<endl;
    // cout<<arr[2]<<endl;
    // cout<<arr[3]<<endl;
    // cout<<arr[4]<<endl;

    // method 2
    // int arr[5] = {1, 2, 3, 4, 5}; // Initialize array in one line
    // for(int i=0;i<5;i++){         // printing all element using for loop
    //     cout<<arr[i]<<endl;
    // }


    // method 3 Size automatically calculated
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    arr[1] = 20;
    arr[2] = 30;
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}