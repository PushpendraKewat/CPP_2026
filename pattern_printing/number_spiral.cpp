#include<iostream>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter the number :";
    cin >> n;

    for(int i = 1; i <= 2*n-1; i++){
        for(int j = 1; j <=2*n-1; j++){
            int a =i,b=j;
            if(a>n) a=2*n-i;
            if(b>n) b=2*n-j;
            int x = std::min(a,b);
            cout<<n - x + 1<<" ";
            // cout<<std::min(a,b)<<" ";
            // if(a<b){
            //     cout<<a<<" ";
            // }
            // else{
            //     cout<<b<<" ";
            // }
        }
        cout << endl;
    }
    return 0;
}
