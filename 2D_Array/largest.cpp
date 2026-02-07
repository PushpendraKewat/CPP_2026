#include<iostream>
#include<climits>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[2][3] ={{1,5,9},{77,8,-9,}};
    // display 
    cout<<"Element in matrix :";
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int mx = INT_MIN;

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
           if(mx<arr[i][j]){
            mx = arr[i][j];
           } 
        }
    }
    cout<<"Maximum element in matrix is :"<<mx;

    return 0;
}