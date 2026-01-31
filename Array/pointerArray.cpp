#include<iostream>

using std::cout;
using std::endl;

int main(){
    
    int arr[] = {1,4,2,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int* ptr1 = arr;
    int* ptr2 = &arr[0];
    cout<<ptr1<<endl;
    cout<<ptr2<<endl;

    return 0;
}