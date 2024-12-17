#ifndef TRAINER_HPP
#define TRAINER_HPP

#include <string>
#include <vector>
#include "../header/Asciimon.hpp"

class Trainer {
private:
    std::string name;
    std::vector<Asciimon> team;

public:
    Trainer(const std::string& name);

    std::string getName() const;
    void addAsciimon(const Asciimon& am);
    Asciimon& getAsciimon(int idx);
    void removeAsciimon(int idx);
    int getTeamCount() const;
    void setParty(std::vector<Asciimon> team) {
        this->team = team;
        for (auto& member : this->team) {
            member.setHealth(member.getStatistics().getMaxHealth());
        }
    }

    std::vector<Asciimon> getTeam() const;
};

#endif 