#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::swap;


int partition(vector<int>& v, int si, int ei){
    int pivot = v[ei];
    int i = si - 1;

    for(int j = si; j < ei; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }

    i++;
    swap(v[i], v[ei]);

    return i;
}

int kthSmallest(vector<int>& v, int si, int ei, int k){
    int pivotIdx = partition(v, si, ei);

    if(pivotIdx == k - 1){
        return v[pivotIdx];
    }

    else if(pivotIdx > k - 1){
        return kthSmallest(v, si, pivotIdx - 1, k);
    }

    else{
        return kthSmallest(v, pivotIdx + 1, ei, k);
    }
}

int main(){
    vector<int> v = {5, 1, 8, 2, 7, 6, 3, 4};

    int k;
    cout << "Enter k: ";
    cin >> k;

    if(k < 1 || k > v.size()){
        cout << "Invalid value of k";
        return 0;
    }

    int ans = kthSmallest(v, 0, v.size() - 1, k);

    cout << k << "th smallest element = " << ans << endl;

    return 0;
}