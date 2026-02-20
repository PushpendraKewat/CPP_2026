#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string str;
    cout << "Enter the string : ";
    getline(cin, str);

    int count = 0;
    int n = str.length();

    for(int i = 0; i < n; i++){

        // first character
        if(i == 0){
            if(n == 1 || str[i] != str[i+1])
                count++;
        }

        // last character
        else if(i == n-1){
            if(str[i] != str[i-1])
                count++;
        }

        // middle characters
        else{
            if(str[i] != str[i-1] && str[i] != str[i+1])
                count++;
        }
    }

    cout << count;
    return 0;
}