#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void removechar(string ans, string original){
    
    if(original.length() == 0){
        cout << ans;
        return;
    }

    char ch = original[0];

    if(ch == 'a'){
        removechar(ans, original.substr(1));
    }
    else{
        removechar(ans + ch, original.substr(1));
    }
}

int main(){
    string str = "Pushpendra kewat";

    removechar("",str);
    // string s = "";
    // for(int i=0;i<str.length();i++){
    //     if(str[i]!='a') s+= str[i];
    // }
    // cout<<s;
    return 0;
}