#include<iostream>

using std::cout;
using std::endl;

int main(){
    int arr[] = {1,4,3,2,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout<<"sum of array : "<<sum;
    return 0;
}