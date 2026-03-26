#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void generate_parentheses(string s, int opening, int closing, int n){
    // base case
    if(s.length() == 2 * n){
        cout << s << endl;
        return;
    }

    // add '(' if possible
    if(opening < n){
        generate_parentheses(s + '(', opening + 1, closing, n);
    }

    // add ')' if valid
    if(closing < opening){
        generate_parentheses(s + ')', opening, closing + 1, n);
    }
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    generate_parentheses("", 0, 0, n);

    return 0;
}