#include <iostream>
using namespace std;

class Bike {
private:
    int tyresize;
    string name;

public:
    // Parameterized constructor
    Bike(int t, string s) {
        tyresize = t;
        name = s;
    }

    void display() {
        cout << tyresize<<endl;
        cout<<name<<endl;
    }
};

int main() {
    Bike tvs(25,"TVS");

    // cout << tvs.tyresize;   // ❌ Error: tyresize is private

    tvs.display();             // ✅ Correct
    return 0;
}