#include <iostream>
using namespace std;

class Player {
private:
    int health;
    int score;
    bool isAlive;

public:
    // Setters
    void Sethealth(int health) {
        this->health = health;
    }

    void Setscore(int score) {
        this->score = score;
    }

    void SetisAlive(bool isAlive) {
        this->isAlive = isAlive;
    }

    // Getters
    int getHealth() {
        return health;
    }

    int getScore() {
        return score;
    }

    bool getisAlive() {
        return isAlive;
    }

    // Add scores
    int addscore(Player a, Player b) {
        return a.getScore() + b.getScore();
    }

    // Return player with maximum score
    Player getMaxScorePlayer(Player a, Player b) {
        if (a.getScore() > b.getScore())
            return a;
        else
            return b;
    }
};

int main() {

    // Compile-time object (Stack)
    Player ram;

    ram.Sethealth(100);
    ram.Setscore(50);
    ram.SetisAlive(true);

    cout << "Ram Details\n";
    cout << "Health : " << ram.getHealth() << endl;
    cout << "Score  : " << ram.getScore() << endl;
    cout << "Alive  : " << ram.getisAlive() << endl;

    cout << endl;

    // Compile-time object (Stack)
    Player harsh;

    harsh.Sethealth(40);
    harsh.Setscore(85);
    harsh.SetisAlive(true);

    cout << "Harsh Details\n";
    cout << "Health : " << harsh.getHealth() << endl;
    cout << "Score  : " << harsh.getScore() << endl;
    cout << "Alive  : " << harsh.getisAlive() << endl;

    cout << endl;

    // Run-time object (Heap)
    Player *urvi = new Player;

    urvi->Sethealth(95);
    urvi->Setscore(101);
    urvi->SetisAlive(true);

    cout << "Urvi Details (Run-Time Object)\n";
    cout << "Health : " << urvi->getHealth() << endl;
    cout << "Score  : " << urvi->getScore() << endl;
    cout << "Alive  : " << urvi->getisAlive() << endl;

    cout << endl;

    cout << "Total score of Ram and Harsh: "
         << ram.addscore(ram, harsh) << endl;

    Player maxPlayer = ram.getMaxScorePlayer(ram, harsh);

    cout << "Maximum Score: " << maxPlayer.getScore() << endl;
    cout << "Health of Highest Scoring Player: "
         << maxPlayer.getHealth() << endl;

    // Free heap memory
    delete urvi;

    return 0;
}