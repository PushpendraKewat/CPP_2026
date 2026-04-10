#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> findClosestElements(vector<int>& v, int k, int x) {
    int n = v.size();
    vector<int> ans;

    if (x < v[0]) {
        for (int i = 0; i < k; i++) ans.push_back(v[i]);
        return ans;
    }

    if (x > v[n - 1]) {
        for (int i = n - k; i < n; i++) ans.push_back(v[i]);
        return ans;
    }

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (v[mid] == x) {
            int left = mid - 1;
            int right = mid + 1;

            ans.push_back(v[mid]);
            k--;

            while (k--) {
                if (left < 0) ans.push_back(v[right++]);
                else if (right >= n) ans.push_back(v[left--]);
                else if (abs(v[left] - x) <= abs(v[right] - x))
                    ans.push_back(v[left--]);
                else
                    ans.push_back(v[right++]);
            }

            sort(ans.begin(), ans.end());
            return ans;
        }
        else if (v[mid] < x) low = mid + 1;
        else high = mid - 1;
    }

    // If x not found
    int left = high;
    int right = low;

    while (k--) {
        if (left < 0) ans.push_back(v[right++]);
        else if (right >= n) ans.push_back(v[left--]);
        else if (abs(v[left] - x) <= abs(v[right] - x))
            ans.push_back(v[left--]);
        else
            ans.push_back(v[right++]);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    int k = 4, x = 3;

    vector<int> result = findClosestElements(v, k, x);

    cout << "Closest "<<k<<" elements to "<<x<<" :";
    for (int num : result) cout << num << " ";
}