#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string str = "pushpendra";
    int count = 0;
    int i = 0;

    while(str[i] != '\0'){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            count++;
        }
        i++;
    }

    cout <<"Total vowel in string are : "<<count;
    return 0;
}
