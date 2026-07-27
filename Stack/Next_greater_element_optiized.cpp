#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

vector<int> nextGreaterElement(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n);
    ans[n-1] = -1;
    stack<int> st;
    ans[n-1] = -1;
    st.push(v[n-1]);
    // traverse right to left
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top() <= v[i]){
            st.pop();
        } 
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(v[i]);
    }
    return ans;
}

int main() {
    vector<int> v = {3,1,2,5,4,6,2,3};

    vector<int> ans = nextGreaterElement(v);

    for (int x : ans){
        cout << x << " ";
    }

    return 0;
}