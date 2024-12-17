#include "../header/Statistics.hpp"
#include <iostream>

using namespace std;


int Statistics::getMaxHealth() const
{
    return maxHealth;
}

int Statistics::getAttack() const
{
    return attack;
}

int Statistics::getDefense() const
{
    return defense;
}

int Statistics::getSpeed() const
{
    return speed;
}

int Statistics::getExpToLevel() const
{
    return expToLevel;
}

int Statistics::getLevel() const
{
    return level;
}

void Statistics::levelUp()
{
    level++;
    expToLevel = expToLevel*5/4 + 2*level + 2;
}
