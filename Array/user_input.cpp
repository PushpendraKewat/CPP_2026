#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[5];
    // input from user
    
    for(int i=0;i<5;i++){
        cout<<"enter "<<i <<" element of array :";
        cin>>arr[i];
    }
    // printing output
    cout << "\nArray elements are:\n";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }

    // update a element 
    arr[2] = 101; // 2 means 3 element
    cout << "\nUpdated Array elements are:\n";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}