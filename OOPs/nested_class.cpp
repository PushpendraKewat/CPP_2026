#include <iostream>
using namespace std;

class Gun {
private:
    int ammo;
    int damage;
    int scope;

public:
    // Setters
    void setAmmo(int ammo) {
        this->ammo = ammo;
    }

    void setDamage(int damage) {
        this->damage = damage;
    }

    void setScope(int scope) {
        this->scope = scope;
    }

    // Getters
    int getAmmo() {
        return ammo;
    }

    int getDamage() {
        return damage;
    }

    int getScope() {
        return scope;
    }
};

class Player {
private:
    int health;
    int score;
    bool isAlive;
    Gun gun;      // Player HAS-A Gun

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

    void setGun(Gun gun) {
        this->gun = gun;
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

    Gun getGun() {
        return gun;
    }

    // Add scores of two players
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

    // Gun for Ram
    Gun akm;
    akm.setAmmo(40);
    akm.setDamage(90);
    akm.setScope(4);

    // Player Ram
    Player ram;
    ram.Sethealth(100);
    ram.Setscore(50);
    ram.SetisAlive(true);
    ram.setGun(akm);

    cout << "===== Ram Details =====" << endl;
    cout << "Health : " << ram.getHealth() << endl;
    cout << "Score  : " << ram.getScore() << endl;
    cout << "Alive  : " << ram.getisAlive() << endl;
    cout << "Ammo   : " << ram.getGun().getAmmo() << endl;
    cout << "Damage : " << ram.getGun().getDamage() << endl;
    cout << "Scope  : " << ram.getGun().getScope() << endl;

    cout << endl;

    // Gun for Harsh
    Gun m4;
    m4.setAmmo(30);
    m4.setDamage(80);
    m4.setScope(6);

    // Player Harsh
    Player harsh;
    harsh.Sethealth(40);
    harsh.Setscore(85);
    harsh.SetisAlive(true);
    harsh.setGun(m4);

    cout << "===== Harsh Details =====" << endl;
    cout << "Health : " << harsh.getHealth() << endl;
    cout << "Score  : " << harsh.getScore() << endl;
    cout << "Alive  : " << harsh.getisAlive() << endl;
    cout << "Ammo   : " << harsh.getGun().getAmmo() << endl;
    cout << "Damage : " << harsh.getGun().getDamage() << endl;
    cout << "Scope  : " << harsh.getGun().getScope() << endl;

    cout << endl;

    // Runtime Player
    Player *urvi = new Player;

    Gun sniper;
    sniper.setAmmo(10);
    sniper.setDamage(100);
    sniper.setScope(8);

    urvi->Sethealth(95);
    urvi->Setscore(101);
    urvi->SetisAlive(true);
    urvi->setGun(sniper);

    cout << "===== Urvi Details =====" << endl;
    cout << "Health : " << urvi->getHealth() << endl;
    cout << "Score  : " << urvi->getScore() << endl;
    cout << "Alive  : " << urvi->getisAlive() << endl;
    cout << "Ammo   : " << urvi->getGun().getAmmo() << endl;
    cout << "Damage : " << urvi->getGun().getDamage() << endl;
    cout << "Scope  : " << urvi->getGun().getScope() << endl;

    cout << endl;

    cout << "Total Score of Ram and Harsh : "
         << ram.addscore(ram, harsh) << endl;

    Player maxPlayer = ram.getMaxScorePlayer(ram, harsh);

    cout << "Highest Score : " << maxPlayer.getScore() << endl;
    cout << "Health of Highest Scoring Player : "
         << maxPlayer.getHealth() << endl;

    Player players[3] = {ram,harsh,*urvi};
    cout<<players[0].getisAlive();

    delete urvi;

    

    return 0;
}