#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[] = {1,2,3,4,5,8,6,4,7,5,4,6,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"size of array is :"<<n<<endl;
    return 0;
}