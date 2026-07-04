#include <iostream>
#include<string>
using namespace std;

class Bike{
    public:
    int tyresize;

    // Constructor( // Default constructor)
    Bike(){
        cout<<"Construct autamatically call";
    }
};

int main() {

    Bike tvs;

    return 0;
}