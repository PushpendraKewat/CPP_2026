#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string bits(int n){
    if(n == 0){
        return "0";
    }

    string ans = "";

    while(n > 0){
        int remainder = n % 2;
        ans += std::to_string(remainder);
        n /= 2;
    }

    int i = 0;
    int j = ans.length() - 1;

    while(i < j){
        char temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
        i++;
        j--;
    }

    return ans;
}

string flipbits(int n){
    string binary = bits(n);

    for(int i = 0; i < binary.length(); i++){
        if(binary[i] == '0')
            binary[i] = '1';
        else
            binary[i] = '0';
    }

    return binary;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Bits of " << n << " : " << bits(n) << endl;
    cout << "Flip bits of " << n << " : " << flipbits(n) << endl;

    return 0;
}