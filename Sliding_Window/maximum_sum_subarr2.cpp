#include<iostream>
#include<climits>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void sliding_window(vector<int>& v, int k) {
    int n = v.size();
    // sliding window approach

    int currsum = 0;

    // First window
    for(int i = 0; i < k; i++) {
        currsum += v[i]; 
    }

    int mxsum = currsum;
    int startIdx = 0;

    int i = 1;
    int j = k;

    while(j < n) {
        currsum += v[j] - v[i - 1];

        if(currsum > mxsum) {
            mxsum = currsum;
            startIdx = i;
        }

        i++;
        j++;
    }

    cout << "Maximum Sum = " << mxsum << endl;
    cout << "Start Index = " << startIdx << endl;
    cout << "End Index = " << startIdx + k - 1 << endl;

    cout << "Subarray: ";
    for(int idx = startIdx; idx <= startIdx + k - 1; idx++) {
        cout << v[idx] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> v = {7,1,2,5,8,4,9,3,6};
    int k;
    cout<<"Enter k :";
    cin>>k;
    sliding_window(v,k);
    return 0;
}