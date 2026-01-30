#include<iostream>
#include<climits>
using std::cout;
using std::endl;

int main(){
    int arr[] = {9,100,1,2,102,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max = INT_MIN;
    int smax = INT_MIN;

    for(int i=0;i<n;i++){
        if(max<arr[i]) max = arr[i];
    }
    cout<<"Largest element is :"<<max<<endl;

    for(int i=0;i<n;i++){
        if(smax<arr[i] && arr[i]!=max) smax = arr[i];
    }
    cout<<"Second largest element is : "<<smax<<endl;

    return 0;
}
