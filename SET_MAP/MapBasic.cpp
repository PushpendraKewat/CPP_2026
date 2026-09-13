#include<iostream>
#include<unordered_map>
#include<string>

using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

int main() {
    unordered_map<string, int> m;

    m["Alice"] = 95;
    m["Bob"] = 88;
    m["Charlie"] = 92;

    for (auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }
    m.erase("Bob");
    cout<<endl;
    for (auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}