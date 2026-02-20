#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int main(){
    string str = "pushpendra";
    cout << "Original : " << str;

    for(int i = 0; i < str.length(); i++){
        if(i % 2 == 0){
            str[i] = 'a';
        }
    }

    cout << endl;
    cout << str;

    return 0;
}
