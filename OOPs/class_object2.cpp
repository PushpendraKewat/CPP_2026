#include<iostream>
#include<string>

using namespace std;

class Player{
    public:
        string name;
        int score;
        int health;
};

int main(){
    Player P1 ; // player is class and amit is object of player class
    P1.name = "Amit";
    P1.score = 82;
    P1.health = 40;
    cout<<"Detail of Player 1 :"<<endl;
    cout<<P1.name<<endl;
    cout<<P1.score<<endl;
    cout<<P1.health<<endl;

    cout<<"\nDetail of Player 2 :"<<endl;
    Player P2;
    P2.name = "Ram";
    P2.score = 90;
    P2.health = 20;
    cout<<P2.name<<endl;
    cout<<P2.score<<endl;
    cout<<P2.health<<endl;

    return 0;
}