#include<iostream>
#include<string>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string decimal_to_binary(int n){
    if(n == 0){
        return "0";
    }

    string ans = "";

    while(n > 0){
        int remainder = n % 2;
        ans += std::to_string(remainder);
        n /= 2;
    }

    // Reverse the string
    int i = 0;
    int j = ans.length() - 1;

    while(i < j){
        std::swap(ans[i], ans[j]);
        i++;
        j--;
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << decimal_to_binary(n) << endl;

    return 0;
}