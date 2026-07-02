#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string name;
    int price;
    int pages;

    int countBooks(int p) {
        if (price < p)
            return 1;
        else
            return 0;
    }

    bool isPresent(string title) {
        if (name == title)
            return true;
        else
            return false;
    }
};

int main() {
    Book HarryPorter;
    HarryPorter.name = "H";
    HarryPorter.price = 1000;
    HarryPorter.pages = 600;

    Book Panchatantra;
    Panchatantra.name = "P";
    Panchatantra.price = 400;
    Panchatantra.pages = 1000;

    cout << HarryPorter.countBooks(2000) << endl;

    cout << HarryPorter.isPresent("H") << endl;

    return 0;
}