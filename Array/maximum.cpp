#include<iostream>
#include<climits> 

using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[] = {9,100,1,2,102,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxval = INT_MIN;

    for(int i=0;i<n;i++){
        if(maxval<arr[i]){
            maxval = arr[i];
        }
    }
    cout<<"maximum element in array :"<<maxval;
    return 0;
}
