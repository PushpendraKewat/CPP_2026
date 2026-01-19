#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    //method 1
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         cout<<"#";
    //     }
    //     for(int k=1;k<=i;k++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // methood 2
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(i+j>=n+1) cout<<"*";
    //         else cout<<" ";
    //     }
    //     cout<<endl;
    // }

    // method 3 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j <= n - i)
            cout<<" ";
            else
            cout<<"*";
        }
        cout << endl;
    }

    return 0;
}