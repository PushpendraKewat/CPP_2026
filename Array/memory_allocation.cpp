#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[] = {1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"size of array is :"<<n<<endl;

    // addres of array
    cout<<"address of whole array : "<<&arr<<endl;
    // entire address of array
    for(int i=0;i<n;i++){
        cout<<i<<" address is :"<<&arr[i]<<endl;
    }
    return 0;
}