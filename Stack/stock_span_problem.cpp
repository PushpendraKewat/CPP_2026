#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

vector<int> stockSpanProblem(vector<int>& v) {
    int n = v.size();
    vector<int> pgi(n); // previous greater index
    pgi[0] = -1;
    stack<int> st;
    st.push(0);
    // traverse left to right
    for(int i=1;i<n;i++){
        while(!st.empty() && v[st.top()] <= v[i]){
            st.pop();
        } 
        if(st.empty()){
            pgi[i] = -1;
        }
        else{
            pgi[i] = st.top();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        pgi[i] = i-pgi[i];
    }
    return pgi;
}

int main() {
    vector<int> v = {100,80,60,81,70,60,75,85};

    vector<int> pgi = stockSpanProblem(v);

    for (int x : pgi){
        cout << x << " ";
    }

    return 0;
}