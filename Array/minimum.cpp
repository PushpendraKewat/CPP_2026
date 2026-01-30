#include<iostream>
#include<climits> 

using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[] = {9,100,1,2,102,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int minval = INT_MAX;

    for(int i=0;i<n;i++){
        if(minval>arr[i]){
            minval = arr[i];
        }
    }
    cout<<"minimum element in array :"<<minval;
    return 0;
}
