#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void decimal_to_binary(int n){
    int original = n;
    if(n == 0){
        cout << "0";
        return;
    }

    string ans = "";

    while(n > 0){
        int remainder = n % 2;
        ans = ans + std::to_string(remainder);
        n /= 2;
    }
    // reverse the string
    int i = 0;
    int j = ans.length() - 1;

    while(i < j){
        char temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;

        i++;
        j--;
    }

    cout << "binary of "<<original<<" is :"<<ans;
}

int main(){
    int n;
    cout<<"Enter decimal no :";
    cin>>n;
    decimal_to_binary(n);
    return 0;
}