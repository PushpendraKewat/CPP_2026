#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void display(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void reversePart(vector<int>& v){
    int i=0 , j = 4;
    while(i<j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

int main(){
    vector<int> v = {1,3,2,4,3,4,1,6};
    cout<<"Original array :";
    display(v);
    cout<<"Reverse part of array :";
    reversePart(v);
    display(v);
    return 0;
}