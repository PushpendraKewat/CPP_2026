#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void change(int arr[], int n){
    arr[0] = 100;
}

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    change(arr, n);

    cout << arr[0];   // 100
    return 0;
}
