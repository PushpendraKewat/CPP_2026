#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> arr = {1,2,3,4,5,5,10,10};

    int n = arr.size();

    // Prefix Sum
    for(int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    int idx = -1;

    for(int i = 0; i < n - 1; i++) {
        if(2 * arr[i] == arr[n - 1]) {
            idx = i;
            break;
        }
    }

    if(idx != -1) {
        cout << "Yes, array can be partitioned" << endl;
        cout << "Partition index = " << idx << endl;
    }
    else {
        cout << "Array cannot be partitioned" << endl;
    }

    return 0;
}