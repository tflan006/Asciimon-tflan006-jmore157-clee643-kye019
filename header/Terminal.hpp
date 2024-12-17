#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <iostream>
#include "Trainer.hpp"
#include "BattleSimulator.hpp"

enum GameState {
    TRAINER_WIN,
    WIN,
    LOSS, 
    CONTINUE,
    QUIT
};

Asciimon chooseStarterAsciimon(int listCount, std::string name, std::ostream& out = std::cout);
void displayIntro(std::ostream& out=std::cout);
void displayMainMenu(std::ostream& out=std::cout);
GameState processUserChoice(char choice, Trainer& player, Trainer& opponent, BattleSimulator& sim, bool comps=false, std::ostream& out=std::cout);
void displayAsciimonNames(const Trainer& trainer, std::ostream& out=std::cout);
GameState fightTrainer(Trainer& player, Trainer& opponent, BattleSimulator& sim, bool comps = false, std::ostream& out=std::cout);
bool fightAsciimon(Trainer& player, Trainer& opponent, BattleSimulator& sim, bool comps = false, std::ostream& out=std::cout);


#endif // TERMINAL_HPP
