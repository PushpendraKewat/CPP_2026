#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

void change(vector<int>& v){
    v[0] = 100;
}

int main(){
    vector<int> v = {1,2,3,4,5};

    cout << "Before change: ";
    for(int x : v) cout << x << " ";

    change(v);

    cout << "\nAfter change: ";
    for(int x : v) cout << x << " ";

    return 0;
}
