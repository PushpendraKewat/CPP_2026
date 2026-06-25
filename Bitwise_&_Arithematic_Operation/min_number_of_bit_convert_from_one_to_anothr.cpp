#include<iostream>
#include<string>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string bits(int n){
    if(n == 0){
        return "0";
    }

    string binary = "";

    while(n > 0){
        binary += char((n & 1) + '0');
        n >>= 1;
    }

    std::reverse(binary.begin(), binary.end());

    return binary;
}

int countbits(int n){
    int count = 0;

    while(n > 0){
        count++;
        n = n & (n - 1);
    }

    return count;
}

int mnflips(int x, int y){
    return countbits(x ^ y);
}

int main(){
    int n;

    cout << "Enter n: ";
    cin >> n;

    int x = 23;
    int y = 32;

    cout << "Bits of " << n << " : " << bits(n) << endl;

    cout << "Count set bits : "
         << countbits(n) << endl;

    cout << "Minimum number of bits to flip from "
         << x << " to " << y << " : "
         << mnflips(x, y) << endl;

    cout << "x ^ y = " << (x ^ y)
         << " (Binary: " << bits(x ^ y) << ")" << endl;

    return 0;
}