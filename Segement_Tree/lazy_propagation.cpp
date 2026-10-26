#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> st;
vector<int> lazy;

void buildTree(vector<int>& nums, int i, int low, int high){
    if(low == high){
        st[i] = nums[low]; //u can also use nums[high]
        return;
    }

    int mid = low + (high - low) / 2;

    buildTree(nums, 2 * i + 1, low, mid);       // left
    buildTree(nums, 2 * i + 2, mid + 1, high);  // right

    st[i] = st[2 * i + 1] + st[2 * i + 2];
}

void push(int i, int low, int high){
    // check for pending lazy update
    if(lazy[i] != 0){
        int rangeSize = high - low + 1;

        st[i] += rangeSize * lazy[i];

        if(low != high){ // send lazy to left and right
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }

        lazy[i] = 0;
    }
}

void updateVal(int i, int low, int high, int index, int val){
    push(i, low, high);

    int mid = low + (high - low) / 2;

    if(low == high){
        st[i] = val;
        return;
    }

    if(index <= mid){ // go left
        updateVal(2 * i + 1, low, mid, index, val);
    }else{ // go right
        updateVal(2 * i + 2, mid + 1, high, index, val);
    }

    // at last update sum
    st[i] = st[2 * i + 1] + st[2 * i + 2];
}

void update(int index, int val, int n){
    updateVal(0, 0, n - 1, index, val);
}

int getSum(int i, int low, int high, int l, int r){
    // check for pending lazy update
    push(i, low, high);

    if(r < low || l > high){ // outside condition
        return 0;
    }

    if(low >= l && high <= r){ // complete overlap
        return st[i];
    }

    int mid = low + (high - low) / 2;

    int leftSum = getSum(2 * i + 1, low, mid, l, r);
    int rightSum = getSum(2 * i + 2, mid + 1, high, l, r);

    return leftSum + rightSum;
}

int sumRange(int left, int right, int n){
    return getSum(0, 0, n - 1, left, right);
}

void updateRange(int i, int low, int high, int l, int r, int val){
    // check for pending lazy update
    push(i, low, high);

    if(r < low || l > high){ // outside condition
        return;
    }

    if(low >= l && high <= r){ // complete overlap
        // update entire low to high
        int rangeSize = high - low + 1;

        st[i] += rangeSize * val;

        if(low != high){ // send lazy to left and right
            lazy[2 * i + 1] += val;
            lazy[2 * i + 2] += val;
        }

        return;
    }

    int mid = low + (high - low) / 2;

    updateRange(2 * i + 1, low, mid, l, r, val);       // left
    updateRange(2 * i + 2, mid + 1, high, l, r, val);  // right

    st[i] = st[2 * i + 1] + st[2 * i + 2];
}

int main(){
    vector<int> nums = {1,4,2,8,6,4,9,3};
    int n = nums.size();

    st.resize(4 * n);
    lazy.resize(4 * n, 0);

    buildTree(nums, 0, 0, n - 1); // inx , low , high

    cout << "Original array: ";
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;

    int l, r, val;
    cout << "Enter range (l and r) : ";
    cin >> l >> r;

    cout << "Sum before update: "
         << sumRange(l, r, n) << endl;

    cout << "Enter value to add: ";
    cin >> val;

    updateRange(0, 0, n - 1, l, r, val);

    cout << "Sum after update: "
         << sumRange(l, r, n) << endl;

    cout << "Total sum: "
         << sumRange(0, n - 1, n) << endl;

    return 0;
}