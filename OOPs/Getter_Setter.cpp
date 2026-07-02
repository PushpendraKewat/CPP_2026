#include <iostream>
using namespace std;

class Player {
private:
    int score;
    int health;

public:
    // Setter functions
    void setScore(int s) {
        score = s;
    }

    void setHealth(int h) {
        health = h;
    }

    // Getter functions
    void showScore() {
        
        cout << "Score : " << score << endl;
    }

    void showHealth() {
        cout << "Health : " << health << endl;
    }
};

int main() {
    Player ram;

    ram.setScore(10);
    ram.setHealth(90);

    ram.showScore();
    ram.showHealth();

    return 0;
}