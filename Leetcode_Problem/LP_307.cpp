// 307. Range Sum Query - Mutable
class NumArray {
public:
    vector<int> st;
    int n;
    void buildTree(vector<int>& nums, int i, int low, int high){
        if(low==high){
            st[i] = nums[low]; //u can also use nums[high]
            return;
        }
        int mid = low + (high-low)/2;
        buildTree(nums,2*i+1,low,mid); // left
        buildTree(nums,2*i+2,mid+1,high); // right
        st[i] = st[2*i+1] + st[2*i+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        buildTree(nums,0,0,n-1);
    }
    
    void updateVal(int i,int low, int high,int& index, int& val){
        int mid = low + (high-low)/2;
        if(low==high){
            st[i] = val;
            return;
        }
        if(index<=mid){ // go left
            updateVal(2*i+1,low,mid,index,val);
        }else{ // go right
            updateVal(2*i+2,mid+1,high,index,val);
        }
        // at last update sum
        st[i] = st[2*i+1] + st[2*i+2];
    }
    void update(int index, int val) {
        updateVal(0,0,n-1,index,val);
    }
    
    int getSum(int i,int low, int high, int& l, int& r){
        if(r<low || l>high){ // outside condition
            return 0;
        }
        if(low>=l && high<=r) return st[i];
        int mid = low + (high-low)/2;
        int leftSum = getSum(2*i+1,low,mid,l,r);
        int rightSum = getSum(2*i+2,mid+1,high,l,r);
        return leftSum + rightSum;
    }
    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left,right);
    }
};