#include<iostream>
#include<vector>

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

int main(){
    vector<int> v = {1,2,3,4,5};
    int n = v.size();
    display(v, n);
    return 0;
}