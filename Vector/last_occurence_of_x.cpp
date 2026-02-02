#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    int x;
    cout << "Enter the value of x : ";
    cin >> x;

    vector<int> v = {6,10,6,12,11,6,0};
    int idx = -1;

    // for(int i=0;i<v.size();i++){
    //     if(v[i]==x){
    //         idx = i;
    //     }
    // }

    // i = v.size()-1 because index start from 0
    for(int i = v.size() - 1; i >= 0; i--){
        if(v[i] == x){
            idx = i;
            break;
        }
    }

    if(idx == -1)
        cout << "Element not found";
    else
        cout << "Last occurrence of " << x << " is at index : " << idx;

    return 0;
}
