#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

vector<int> previousGreaterElement(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n);
    ans[0] = -1;
    stack<int> st;
    st.push(v[0]);
    // traverse left to right
    for(int i=1;i<n;i++){
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

    vector<int> ans = previousGreaterElement(v);

    for (int x : ans){
        cout << x << " ";
    }

    return 0;
}