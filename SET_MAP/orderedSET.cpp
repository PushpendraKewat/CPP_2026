#include<iostream>
#include<set>
#include<map>

using std::cout;
using std::endl;
using std::map;
using std::set;

int main(){
    // ordered set and map
    
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(3);

    for(int x : s){
        cout<<x<<" ";
    }
    return 0;
}