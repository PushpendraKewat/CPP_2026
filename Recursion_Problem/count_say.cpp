#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string count_say(int n){
    if(n == 1) return "1";

    string str = count_say(n - 1);

    string ans = "";
    int freq = 1;
    char ch = str[0];

    for(int i = 1; i < str.size(); i++){
        if(str[i] == ch){
            freq++;
        }
        else{
            ans += std::to_string(freq);
            ans += ch;
            freq = 1;
            ch = str[i];
        }
    }

    ans += std::to_string(freq);
    ans += ch;

    return ans;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << count_say(n) << endl;

    return 0;
}