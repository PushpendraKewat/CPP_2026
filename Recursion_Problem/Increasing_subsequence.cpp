#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void subsequence(vector<int>& arr, int idx, vector<int>& ans, int k){
    int n = arr.size();

    // base case
    if(idx == n){
        if(ans.size() == k){
           for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
           }
           cout<<endl;
        }
        return; 
    }

    // include
    ans.push_back(arr[idx]);
    subsequence(arr, idx + 1, ans, k);

    // backtrack
    ans.pop_back();

    // exclude
    subsequence(arr, idx + 1, ans, k);
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 3;
    vector<int> ans;

    subsequence(arr, 0, ans, k);

    return 0;
}