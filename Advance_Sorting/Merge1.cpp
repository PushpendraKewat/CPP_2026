#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> merge(vector<int>& v1, vector<int>& v2) {

    vector<int> ans;

    int i = 0;
    int j = 0;

    // Compare elements
    while(i < v1.size() && j < v2.size()) {

        if(v1[i] < v2[j]) {
            ans.push_back(v1[i]);
            i++;
        }
        else {
            ans.push_back(v2[j]);
            j++;
        }
    }

    // Remaining elements of v1
    while(i < v1.size()) {
        ans.push_back(v1[i]);
        i++;
    }

    // Remaining elements of v2
    while(j < v2.size()) {
        ans.push_back(v2[j]);
        j++;
    }

    return ans;
}

int main() {

    vector<int> v1 = {1,4,5,8};
    vector<int> v2 = {2,3,6,7,10,12};

    vector<int> ans = merge(v1, v2);

    cout << "Merged Array:\n";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}