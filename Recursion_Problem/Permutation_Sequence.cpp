#include<iostream>
#include<string>
using namespace std;

string kthPermutation(string original, int k, string ans){
    // base case
    if(original.size() == 0) return ans;

    int n = original.size();

    // calculate (n-1)!
    int fact = 1;
    for(int i = 2; i < n; i++){
        fact *= i;
    }

    // find index
    int idx = k / fact;
    if(k % fact == 0) idx--;

    // pick character
    char ch = original[idx];

    // remove character
    string left = original.substr(0, idx);
    string right = original.substr(idx + 1);
    string newOriginal = left + right;

    // update k
    if(k % fact == 0) k = fact;
    else k = k % fact;

    // recursive call
    return kthPermutation(newOriginal, k, ans + ch);
}

int main(){
    int n = 3, k = 3;

    // create "123...n"
    string str = "";
    for(int i = 1; i <= n; i++){
        str += to_string(i);
    }

    cout << kthPermutation(str, k, "") << endl; // Output: 213

    return 0;
}