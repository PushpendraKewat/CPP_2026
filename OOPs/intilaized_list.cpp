#include <iostream>
using namespace std;

class Bike {
private:
    string name;
    int tyresize;

public:
    Bike(string n, int t) : name(n), tyresize(t) {
    }

    void display() {
        cout << name << " " << tyresize << endl;
    }
};

int main(){
    Bike b1("TVS",20);
    b1.display();
}