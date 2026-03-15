#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int mazepath(int sr,int sc,int er,int ec,string path){

    if(sr>er || sc>ec) return 0;

    if(sr==er && sc==ec){
        cout << path << endl;   // print path
        return 1;               // one valid way
    }

    int rightways = mazepath(sr, sc+1, er, ec, path + "R");
    int downways  = mazepath(sr+1, sc, er, ec, path + "D");

    return rightways + downways;
}

int main(){
    int total = mazepath(1,1,3,3,"");
    cout << "Total ways = " << total;
    return 0;
}