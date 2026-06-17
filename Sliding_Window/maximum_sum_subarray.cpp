#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void sliding_window(vector<int>& v, int k) {
    int n = v.size();

    int mxsum = 0;
    int start = -1;
    int end = -1;
    // brute force
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;

        for (int j = i; j < i + k; j++) {
            sum += v[j];
        }

        if (sum > mxsum) {
            mxsum = sum;
            start = i;
            end = i + k - 1;
        }
    }

    cout << "Maximum Sum = " << mxsum << endl;
    cout << "Start Index = " << start << endl;
    cout << "End Index = " << end << endl;

    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << v[i] << " ";
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