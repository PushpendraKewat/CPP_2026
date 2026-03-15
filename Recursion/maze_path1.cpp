#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int mazepath(int sr,int sc, int er, int ec){
    if(sr>er || sc>ec) return 0;
    if(sr==er || sc==ec) return 1;

    int rightways = mazepath(sr,sc+1,er,ec);
    int downways = mazepath(sr+1,sc,er,ec);

    int totalways = rightways + downways;

    return totalways; 
}

int main(){
    cout<<mazepath(0,0,3,3);
    return 0;
}