#include<iostream>
#include<map>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main() {
    map<int, string> m;

    m[3] = "Three";
    m[1] = "One";
    m[4] = "Four";
    m[2] = "Two";

    for(auto p : m) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}