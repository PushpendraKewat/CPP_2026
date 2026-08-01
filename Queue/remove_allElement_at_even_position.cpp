#include<iostream>
#include<queue>
#include<stack>

using std::cout;
using std::endl;
using std::queue;
using std::stack;

void display(queue<int>& q){
    int n = q.size();
    for(int i=0;i<n;i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

void  removeAtEven(queue<int>& q){
    int n = q.size();
    for(int i=0;i<n;i++){ // 0 based indexing
        int x = q.front();
        q.pop();
        if(i%2!=0){
            q.push(x);
        }
    }
}

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    display(q);
    removeAtEven(q);
    display(q);
    return 0;
}