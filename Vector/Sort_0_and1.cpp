#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void display(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void sort1(vector<int>& v){
    int no0 = 0, no1 = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i] == 0) no0++;
        else no1++;
    }

    for(int i = 0; i < v.size(); i++){
        if(i < no0)
            v[i] = 0;
        else
            v[i] = 1;
    }
}

void twoPointer(vector<int>& v){
   int i = 0, j = v.size()-1;
   while (i<j){
    if(v[i]==0) i++;
    else if(v[j]==j) j--;
    else{
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    } 
   }
   
}


int main(){
    vector<int> v = {1,1,0,1,0,1,1,1};
    cout<<"Original Array : ";
    display(v);
    sort1(v);
    cout<<"Sort 0s and 1s :";
    display(v);
    twoPointer(v);
    cout<<"Sort 0s and 1s with two pointer :";
    display(v);
    return 0;
}
