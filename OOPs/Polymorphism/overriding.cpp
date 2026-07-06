#include<iostream>
using namespace std;

class Vehicle{
public:
    virtual void show(){
        cout<<"A ka show\n";
    }
};

class Bike : public Vehicle{
public:
    void show() override{
        cout<<"B ka show\n";
    }
};

int main(){

    // Vehicle* ptr = new Bike;
    // ptr->show();

    Bike b;
    Vehicle* ptr = &b;
    ptr->show();
    b.show();

    return 0;
};