#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void display(vector<int>& ans){
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

void mergetwo(vector<int>& v1, vector<int>& v2){
    vector<int> ans(v1.size() + v2.size());

    int i = 0, j = 0, k = 0;

    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            ans[k] = v1[i];
            i++;
        }
        else{
            ans[k] = v2[j];
            j++;
        }
        k++;
        
    }

    // remaining elements of v1
    while(i < v1.size()){
        ans[k] = v1[i];
        i++;
        k++;
    }

    // remaining elements of v2
    while(j < v2.size()){
        ans[k] = v2[j];
        j++;
        k++;
    }

    display(ans);
}

int main(){
    vector<int> v1 = {1,4,5,8};
    vector<int> v2 = {2,3,6,7,10};

    mergetwo(v1, v2);

    return 0;
}
