#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    // Step 1: Sort both arrays
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0; // child pointer
    int j = 0; // cookie pointer
    int count = 0;

    // Step 2: Assign cookies
    while(i < g.size() && j < s.size()){

        if(s[j] >= g[i]){
            count++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    cout << "Content Children = " << count << endl;

    return 0;
}