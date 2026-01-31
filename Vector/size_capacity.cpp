#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


int main(){
    vector<int> v;
    v.push_back(1);
    cout<<"size :"<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"size :"<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"size :"<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;

    v.push_back(4);
    cout<<"size :"<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;

    v.push_back(5);

    cout<<"size :"<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;
    return 0;
}
