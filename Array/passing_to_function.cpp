#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void change(int arr[]){
    arr[0] = 14;
}

int main(){
    
    int arr[] = {1,4,2,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before change :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    change(arr);
    cout<<endl<<"After change : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}