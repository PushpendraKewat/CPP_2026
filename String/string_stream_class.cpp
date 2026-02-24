#include<iostream>
#include<string>
#include<sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string s = "raghav is a  math   teacher";
    std::stringstream ss(s);
    string temp;

    while(ss>>temp){
        cout<<temp<<endl;
    }
    return 0;
}