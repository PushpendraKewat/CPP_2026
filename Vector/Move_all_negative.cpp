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

void move(vector<int>& v){
    int i = 0, j = v.size()-1;
    while(i<j){
        if(v[i]<0){
            i++;
        }
        else if(v[j]>0){
            j--;
        }
        else{
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
}

void moveStable(vector<int>& v){
    vector<int> ans;
    // negative
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            ans.push_back(v[i]);
        }
    }
    // postivie
    for(int i=0;i<v.size();i++){
        if(v[i]>=0){
            ans.push_back(v[i]);
        }
    }
    v = ans;
}


    int main(){
    vector<int> v = {1,-2,3,-4,-5,6,8};

    cout << "Original Array : ";
    display(v);

    vector<int> v1 = v;   // copy for in-place method
    vector<int> v2 = v;   // copy for stable method

    move(v1);
    cout << "Move negative to beginning : ";
    display(v1);

    moveStable(v2);
    cout << "Move negative and maintain order : ";
    display(v2);

    return 0;
    
    }
