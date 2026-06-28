#include <iostream>
#include<vector>


using std::cout;
using std::endl;
using std::vector;

bool isPrime(int n){
    if(n<=1) return false;

    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int PrimeDiagonal(vector<vector<int>>& nums){

    int n = nums.size();
    int mx = 0;

    for(int i=0;i<n;i++){
        if(isPrime(nums[i][i])){
            mx = std::max(mx,nums[i][i]);
        }
        if(isPrime(nums[i][n-i-1])){
            mx = std::max(mx,nums[i][n-i-1]);
        }
    }
    return mx;

}

int main(){
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Largest Prime in Diagonal is :";
    cout<<PrimeDiagonal(nums);
    return 0;
}