#include<iostream>
#include<vector>
#include<climits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// display using recursion
void display(vector<int>& v, int n){
    if(n == 0) return;  

    display(v, n - 1);   
    cout << v[n - 1] << " ";  
}
// iterative max
void maxval(vector<int>& v){
    int n = v.size();
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        if(v[i]>mx){
            mx = v[i];
        }
    }
    cout<<mx;
}
// recursion max
int rmax(vector<int>& v,int n){
    if(n==1) return v[0]; // base case
    int smallAns = rmax(v, n - 1);
    return (v[n-1] > smallAns) ? v[n-1] : smallAns;
}

int main(){
    vector<int> v = {2,1,6,3,9,0,2};
    int n = v.size();

    cout << "Array: ";
    display(v, n);
    cout << endl;

    cout << "Max (loop): ";
    maxval(v);
    cout << endl;

    cout << "Max (recursion): ";
    cout << rmax(v,n);

    return 0;
}