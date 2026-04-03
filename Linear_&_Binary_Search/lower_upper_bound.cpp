#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int lowerBound(vector<int>& v, int x){
    int low = 0, high = v.size() - 1;
    int ans = v.size();

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(v[mid] >= x){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>& v, int x){
    int low = 0, high = v.size() - 1;
    int ans = v.size();

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(v[mid] > x){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,2,4,5,9,15,18,21,24};
    int x = 18;

    int lb = lowerBound(v,x);
    int ub = upperBound(v,x);

    // Lower Bound
    if(lb < v.size()){
        cout << "Lower Bound -> Index: " << lb 
             << ", Value: " << v[lb] << endl;
    } else {
        cout << "Lower Bound -> Not found (no element >= x)" << endl;
    }

    // Upper Bound
    if(ub < v.size()){
        cout << "Upper Bound -> Index: " << ub 
             << ", Value: " << v[ub] << endl;
    } else {
        cout << "Upper Bound -> Not found (no element > x)" << endl;
    }

    return 0;
}