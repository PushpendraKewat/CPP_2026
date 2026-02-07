#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n,m;
    cout<<"Enter rows :";
    cin>>n;
    cout<<"Enter columns :";
    cin>>m;
    int arr[n][m];
    cout<<"Enter element in 2D array :";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // display
    cout<<"Element in the array :";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}