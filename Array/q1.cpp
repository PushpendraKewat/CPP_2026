#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"enter no of student :";
    cin>>n;
    int marks[n];
    // user input of n size array 
    cout<<"\nEnter "<<n<<" element of array :";
    for(int i=0;i<n;i++){
        cin>>marks[i];
    }
    // print index with marks less thab 35
    for( int i=0;i<n;i++){
        if(marks[i]<35){
            cout<<"index "<<i<<" marks :"<<marks[i]<<endl;
        }
    }
    return 0;
}