#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cricketer {
private:
    string name;
    int age;
    int testMatches;
    float average;

public:
    // Setters
    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setTestMatches(int testMatches) {
        this->testMatches = testMatches;
    }

    void setAverage(float average) {
        this->average = average;
    }

    // Getters
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    int getTestMatches() {
        return testMatches;
    }

    float getAverage() {
        return average;
    }
};

int main() {

    // Vector of 11 Cricketer objects
    vector<Cricketer> players(11);

    // Input
    for (int i = 0; i < players.size(); i++) {

        string name;
        int age;
        int matches;
        float average;

        cout << "\nEnter details of Cricketer " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Test Matches: ";
        cin >> matches;

        cout << "Average: ";
        cin >> average;

        players[i].setName(name);
        players[i].setAge(age);
        players[i].setTestMatches(matches);
        players[i].setAverage(average);
    }

    cout << "\n\n========== PLAYER DETAILS ==========\n";

    // Output
    for (int i = 0; i < players.size(); i++) {

        cout << "\nCricketer " << i + 1 << endl;
        cout << "Name         : " << players[i].getName() << endl;
        cout << "Age          : " << players[i].getAge() << endl;
        cout << "Test Matches : " << players[i].getTestMatches() << endl;
        cout << "Average      : " << players[i].getAverage() << endl;
    }

    return 0;
}