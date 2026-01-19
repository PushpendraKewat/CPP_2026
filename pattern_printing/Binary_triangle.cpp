#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    //method 1
    // int a;
    // for(int i=1;i<=n;i++){
    //     if(i%2!=0 ){
    //         a=1;
    //        }
    //        else{
    //         a = 0;
    //        }
    //     for(int j=1;j<=i;j++){
    //        cout<<a;
    //        // flipping
    //        if(a==1 ) a = 0;
    //        else a = 1;
    //     }
    //     cout<<endl;
    // }

   for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if( (i + j) % 2 == 0 ){
            cout << 1;
            }
            else{
            cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}