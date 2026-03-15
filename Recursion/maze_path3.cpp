#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int mazepath(int rows,int cols){
    if(rows < 1 || cols < 1) return 0;
    if(rows == 1 || cols == 1) return 1;

    int rightways = mazepath(rows, cols-1);
    int downways  = mazepath(rows-1, cols);

    return rightways + downways;
}

void printpath(int rows, int cols, string s){

    if(rows == 1 && cols == 1){
        cout << s << endl;
        return;
    }

    if(cols > 1)
        printpath(rows, cols-1, s + "R");

    if(rows > 1)
        printpath(rows-1, cols, s + "D");
}

int main(){

    cout <<"total ways :"<< mazepath(3,3);
    cout << endl;

    printpath(3,3,"");

    return 0;
}