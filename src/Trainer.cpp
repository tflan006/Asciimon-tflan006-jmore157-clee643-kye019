#include "../header/Trainer.hpp"


Trainer::Trainer(const std::string& name) 
    : name(name) {
}

std::string Trainer::getName() const {
    return name;
}

void Trainer::addAsciimon(const Asciimon& am) {
    team.push_back(am);
}

Asciimon& Trainer::getAsciimon(int idx) {
    // if (idx < 0 || idx >= team.size()) {
    //     throw std::out_of_range("Index out of range");
    // }
    return team[idx];
}

void Trainer::removeAsciimon(int idx) {
    // if (idx < 0 || idx >= team.size()) {
    //     throw std::out_of_range("Index out of range");
    // }
    team.erase(team.begin() + idx);
}

int Trainer::getTeamCount() const {
    return team.size();
}

std::vector<Asciimon> Trainer::getTeam() const
{
    return team;
}