#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void combination_sum(vector<int>& arr, vector<int>& ans, int target, int idx){

    // base case
    if(target == 0){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    if(target < 0 || idx == arr.size()) return;

    // include current element
    ans.push_back(arr[idx]);
    combination_sum(arr, ans, target - arr[idx], idx); // same index
    ans.pop_back(); // backtrack

    // exclude current element
    combination_sum(arr, ans, target, idx + 1);
}

int main(){
    vector<int> arr = {2,3,5};
    int target = 7;

    vector<int> ans;
    combination_sum(arr, ans, target, 0);

    return 0;
}