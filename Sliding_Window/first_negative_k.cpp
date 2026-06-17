#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void first_negative(vector<int>& v, int k){
    int n = v.size();
    vector<int> ans;

    for(int i = 0; i <= n - k; i++){
        bool found = false;

        for(int j = i; j < i + k; j++){
            if(v[j] < 0){
                ans.push_back(v[j]);
                found = true;
                break;
            }
        }

        if(!found)
            ans.push_back(0);
    }

    for(int x : ans)
        cout << x << " ";
}

void first_negative_sliding_window(vector<int>& v, int k) {
    int n = v.size();

    vector<int> ans;
    int p = -1; // index of first negative number

    // First window
    for(int i = 0; i < k; i++) {
        if(v[i] < 0) {
            p = i;
            break;
        }
    }

    if(p != -1)
        ans.push_back(v[p]);
    else
        ans.push_back(0);

    int i = 1;
    int j = k;

    while(j < n) {

        // Previous negative still inside current window
        if(p >= i) {
            ans.push_back(v[p]);
        }
        else {
            p = -1;

            // Find first negative in current window
            for(int idx = i; idx <= j; idx++) {
                if(v[idx] < 0) {
                    p = idx;
                    break;
                }
            }

            if(p != -1)
                ans.push_back(v[p]);
            else
                ans.push_back(0);
        }

        i++;
        j++;
    }

    for(int x : ans) {
        cout << x << " ";
    }
}
int main(){
    vector<int> v = {2,-3,4,4,-7,-1,4,-2,6};

    int k;
    cout << "Enter k: ";
    cin >> k;

    // first_negative(v, k);
    first_negative_sliding_window(v,k);

    return 0;
}