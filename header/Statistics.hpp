#ifndef __STATISTICS_HPP
#define __STATISTICS_HPP

using namespace std;


class Statistics{

private:
int maxHealth;
int attack;
int defense;
int speed;
int level;
int expToLevel;

public:
Statistics(int maxHealth, int attack, int defense, int speed, int level)
: maxHealth(maxHealth), attack(attack), defense(defense), speed(speed), level(level), expToLevel(10) {}

int getMaxHealth() const;
int getAttack() const;
int getDefense() const;
int getSpeed() const;
int getExpToLevel() const;
int getLevel() const;
void levelUp();

};
#endif