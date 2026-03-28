#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    vector<int> v = {1,2,4,5,7,15,18,21};
    int target = 18;

    int index = -1;

    for(int i = 0; i < v.size(); i++){
        if(v[i] == target){
            index = i;
            break;
        }
    }

    if(index != -1){
        cout << "Found "<<target<<" at index: " << index << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}