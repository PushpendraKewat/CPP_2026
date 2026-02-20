#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string str = "abcdefgh";
    int n = str.length();
    int j = n/2-1;
    int i=0;
    while(i<j){
        std::swap(str[i],str[j]);
        i++;
        j--;
    }
    cout<<str;
    return 0;
}
