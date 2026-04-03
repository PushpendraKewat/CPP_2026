#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

// Linear Search (O(n))
int smallestMissingLinear(vector<int>& v){
    int n = v.size();

    for(int i = 0; i < n; i++){
        if(v[i] != i){
            return i;
        }
    }
    return n;
}

//  Binary Search (O(log n))
int smallestMissingBinary(vector<int>& v){
    int low = 0;
    int high = v.size() - 1;
    int ans = v.size(); // default = n

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(v[mid] == mid){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {0,1,2,3,4,8,9,12};

    int linearAns = smallestMissingLinear(v);
    int binaryAns = smallestMissingBinary(v);

    cout << "Linear Answer: " << linearAns << endl;
    cout << "Binary Answer: " << binaryAns << endl;

    return 0;
}