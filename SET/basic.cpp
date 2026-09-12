#include<iostream>
#include<unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // for each loop
    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
    int target = 3;
    if(s.find(target)!=s.end()){
        cout<<"exist";
    }else{
        cout<<"not exist";
    }
    return 0;
}