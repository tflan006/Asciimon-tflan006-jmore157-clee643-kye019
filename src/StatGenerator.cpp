#include "../header/StatGenerator.hpp"
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h> 

using namespace std;

Statistics StatGenerator::generateStats()
{
    srand (time(NULL));

    int maxHealth = (rand()%100 + 101); //between 100-200
    int attack = (rand()%50 + 51); //between 50-100
    int defense = (rand()%50 + 51); //between 50-100
    int speed = (rand()%25 + 1); //between 1-25

    Statistics stats(maxHealth, attack, defense, speed, 1);
    return stats;
}