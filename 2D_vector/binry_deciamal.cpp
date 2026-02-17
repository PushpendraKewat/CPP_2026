#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    vector<int> v = {1,1,0,0,1,0,1};
    int n = v.size();

    int sum = 0;
    int x = 1;
    for(int i=n-1;i>=0;i--){
        sum += v[i]*x;
        x *= 2;
    }
    cout<<sum;
    return 0;
}