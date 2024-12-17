#ifndef __ASCIIMON_HPP
#define __ASCIIMON_HPP

#include <string>
#include <vector>

#include "Statistics.hpp"
#include "ElementalType.hpp"
#include "Move.hpp"

using namespace std;

class Asciimon{
private:
string name;
int health;
ElementalType type;
vector<Move> moveSet;
Statistics statistics;
int experience;


public:

Asciimon(string name, int health, ElementalType type, int experience, Statistics stats) :
name(name), health(health), type(type), experience(experience), statistics(stats)  {}

Asciimon(string name, ElementalType type, int experience, Statistics stats) :
name(name), health(stats.getMaxHealth()), type(type), experience(experience), statistics(stats)  {}

string getName() const;
int getHealth() const;
ElementalType getType() const;
Statistics getStatistics() const;
int getExperience() const;
vector<Move> getMoveSet() const;
void addMove(Move);

int gainExperience(int exp);

void setHealth(int health);

};
#endif