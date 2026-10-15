/* u are given a string consist of small
alphabet consider no repeation of character ,
print all the possible peruation/arreangemnent
of the given string
*/

#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

// Without backtracking
void permutation(string& str, int idx = 0) {
    if(idx == str.size()) {
        cout << str << endl;
        return;
    }

    for(int i = idx; i < str.size(); i++) {
        std::swap(str[idx], str[i]);

        permutation(str, idx + 1);
    }
}

// With backtracking
void permutation_backtracking(string& str, int idx = 0) {
    if(idx == str.size()) {
        cout << str << endl;
        return;
    }
    for(int i = idx; i < str.size(); i++) {
        std::swap(str[idx], str[i]);

        permutation_backtracking(str, idx + 1);

        std::swap(str[idx], str[i]); // backtrack
    }
}

int main() {
    string str = "abc";

    cout << "Permutation without backtracking:\n";
    permutation(str);

    str = "abc"; // reset string

    cout << "\nPermutation with backtracking:\n";
    permutation_backtracking(str);

    return 0;
}