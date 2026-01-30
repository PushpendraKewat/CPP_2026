#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    bool found = false;

    cout << "Enter element you want to find in the array: ";
    cin >> x;

    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            cout << "Element found at index " << i << endl;
            found = true;
            break;   
        }
    }

    if(!found){
        cout << x << " element not in array";
    }

    return 0;
}
