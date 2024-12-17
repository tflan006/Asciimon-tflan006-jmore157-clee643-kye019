#include <string>
#include <vector>
#include <cassert>
#include "../header/Asciimon.hpp"
#include "../header/ElementalType.hpp"


using namespace std;

string Asciimon::getName() const
{
    return name;
}

int Asciimon::getHealth() const
{
    return health;
}

ElementalType Asciimon::getType() const
{
    return type;
}

Statistics Asciimon::getStatistics() const
{
    return statistics;
}

int Asciimon::getExperience() const
{
    return experience;
}

vector<Move> Asciimon::getMoveSet() const
{
    return moveSet;
}

int Asciimon::gainExperience(int exp)
{
    assert(exp >= 0);
    experience += exp;

    int levels{};
    while (experience >= statistics.getExpToLevel()) {
        experience -= statistics.getExpToLevel();
        statistics.levelUp();
        ++levels;
    }
    return levels;
}

void Asciimon::addMove(Move move)
{
    moveSet.push_back(move);
}

void Asciimon::setHealth(int health) {
    this->health = std::min(health, statistics.getMaxHealth());
}
