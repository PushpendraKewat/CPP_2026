#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    // 1️⃣ Create string
    string s = "pushpendra";
    cout << "Original string: " << s << endl;

    // 2️⃣ length / size
    cout << "Length: " << s.length() << endl;

    // 3️⃣ push_back
    s.push_back('k');
    cout << "After push_back: " << s << endl;

    // 4️⃣ pop_back
    s.pop_back();
    cout << "After pop_back: " << s << endl;

    // 5️⃣ append
    s.append(" kewat");
    cout << "After append: " << s << endl;

    // 6️⃣ + operator
    string a = " C++";
    string b = s + a;
    cout << "After + operator: " << b << endl;

    // 7️⃣ substr
    cout << "Substring (0,4): " << s.substr(0,4) << endl;

    // 8️⃣ find
    cout << "Find 'pen': " << s.find("pen") << endl;

    // 9️⃣ insert
    string s2 = "pushdra";
    s2.insert(4, "pen");
    cout << "After insert: " << s2 << endl;

    // 🔟 erase
    s2.erase(4,3);
    cout << "After erase: " << s2 << endl;

    // 1️⃣1️⃣ reverse
    string rev = s;
    reverse(rev.begin(), rev.end());
    cout << "Reversed string: " << rev << endl;

    // 1️⃣2️⃣ access characters
    cout << "First char: " << s[0] << endl;
    cout << "Second char using at(): " << s.at(1) << endl;

    // 1️⃣3️⃣ iterate string
    cout << "Characters: ";
    for(char ch : s){
        cout << ch << " ";
    }
    cout << endl;

    // 1️⃣4️⃣ toupper / tolower
    string temp = s;
    for(char &ch : temp){
        ch = toupper(ch);
    }
    cout << "Uppercase: " << temp << endl;

    // 1️⃣5️⃣ clear
    temp.clear();
    cout << "After clear, is empty? " << temp.empty() << endl;

    return 0;
}
