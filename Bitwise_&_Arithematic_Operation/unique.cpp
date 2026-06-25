#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

int uniqueUsingSort(vector<int> v){
    std::sort(v.begin(), v.end());

    for(int i = 0; i < v.size() - 1; i += 2){
        if(v[i] != v[i + 1]){
            return v[i];
        }
    }

    return v[v.size() - 1];
}

int uniqueUsingXOR(vector<int>& v){
    int ans = 0;

    for(int num : v){
        ans ^= num;
    }

    return ans;
}

int main(){
    vector<int> v = {2,1,3,2,1,5,5,6,3};

    cout << "Unique element (Sorting): "
         << uniqueUsingSort(v) << endl;

    cout << "Unique element (XOR): "
         << uniqueUsingXOR(v) << endl;

    return 0;
}