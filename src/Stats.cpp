#include <iostream>
#include "../header/Stats.hpp"

using namespace std;

void displayAsciimonStats(const Asciimon& asciimon) {
    cout << "********************************************" << endl;
    cout << "*               ASCIIMON STATS             *" << endl;
    cout << "********************************************" << endl;
    cout << "* Name: " << asciimon.getName() << endl;
    cout << "* Health: " << asciimon.getHealth() << endl;
    cout << "* Experience: " << asciimon.getExperience() << endl;
    cout << "* Type: " << static_cast<int>(asciimon.getType()) << endl; // Assuming ElementalType is an enum
    cout << "* Statistics: " << endl;
    cout << "  - Max Health: " << asciimon.getStatistics().getMaxHealth() << endl;
    cout << "  - Attack: " << asciimon.getStatistics().getAttack() << endl;
    cout << "  - Defense: " << asciimon.getStatistics().getDefense() << endl;
    cout << "  - Speed: " << asciimon.getStatistics().getSpeed() << endl;
    cout << "* Moves: " << endl;
    for (const auto& move : asciimon.getMoveSet()) {
        cout << "  - " << move.getName() << ": " << move.getDescription() << endl;
    }
    cout << "********************************************" << endl;
}

void displayLevelUp(const Asciimon& oldAsciimon, const Asciimon& newAsciimon) {
    cout << "********************************************" << endl;
    cout << "*               LEVEL UP!                  *" << endl;
    cout << "********************************************" << endl;
    cout << "* " << oldAsciimon.getName() << " has reached a new level!" << endl;
    cout << "* Health: " << oldAsciimon.getHealth() << " -> " << newAsciimon.getHealth() << endl;
    cout << "* Max Health: " << oldAsciimon.getStatistics().getMaxHealth() << " -> " << newAsciimon.getStatistics().getMaxHealth() << endl;
    cout << "* Attack: " << oldAsciimon.getStatistics().getAttack() << " -> " << newAsciimon.getStatistics().getAttack() << endl;
    cout << "* Defense: " << oldAsciimon.getStatistics().getDefense() << " -> " << newAsciimon.getStatistics().getDefense() << endl;
    cout << "* Speed: " << oldAsciimon.getStatistics().getSpeed() << " -> " << newAsciimon.getStatistics().getSpeed() << endl;

    if (oldAsciimon.getMoveSet().size() < newAsciimon.getMoveSet().size()) {
        cout << "* New move learned: " << newAsciimon.getMoveSet().back().getName() << endl;
    }
    cout << "********************************************" << endl;
}
