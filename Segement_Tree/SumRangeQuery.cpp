
#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> st;

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

void updateVal(int i, int low, int high, int index, int val){
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

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int n = nums.size();

    st.resize(4 * n);

    buildTree(nums, 0, 0, n - 1);

    cout << "Original array: ";
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;

    int left = 1, right = 3;
    cout << "Sum from index " << left << " to " << right
         << " = " << sumRange(left, right, n) << endl;

    int index = 2, val = 10;
    update(index, val, n);
    nums[index] = val;

    cout << "After updating index " << index << " to " << val << ": ";
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;

    cout << "Updated range sum = "
         << sumRange(left, right, n) << endl;

    return 0;
}
