#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    vector<int> v = {1,3,2,4,3,4,1,6};
    int n = v.size();
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        ans.push_back(v[i]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    // int i = 0, j = n-1;
    // while(i<j){
    //     int temp = v[i];
    //     v[i] = v[j];
    //     v[j] = temp;
    //     i++;
    //     j--;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    return 0;
}