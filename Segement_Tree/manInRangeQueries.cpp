
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

vector<int> st;

void buildTree(vector<int>& v, int i, int low, int high){
    if(low == high){
        st[i] = v[low];
        return;
    }
    int mid = low + (high - low) / 2;

    buildTree(v, 2 * i + 1, low, mid);       // left subtree
    buildTree(v, 2 * i + 2, mid + 1, high);  // right subtree

    st[i] = max(st[2 * i + 1], st[2 * i + 2]);
}

int getMax(int i, int low, int high, int l, int r){

    if(r < low || l > high){ // outside condition
        return INT_MIN;
    }

    if(l <= low && high <= r){ // complete overlap condition
        return st[i];
    }
    int mid = low + (high - low) / 2;

    int left = getMax(2 * i + 1, low, mid, l, r);
    int right = getMax(2 * i + 2, mid + 1, high, l, r);
    return max(left, right);
}

int main(){
    vector<int> v = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = v.size();
    st.resize(4 * n);
    buildTree(v, 0, 0, n - 1);
    int l, r;
    cout << "Enter the range: ";
    cin >> l >> r;

    cout << "Maximum element: "<< getMax(0, 0, n - 1, l, r) << endl;

    return 0;
}
