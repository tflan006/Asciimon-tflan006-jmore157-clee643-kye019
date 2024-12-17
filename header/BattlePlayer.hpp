#pragma once

#ifndef BATTLE_PLAYER_HPP
#define BATTLE_PLAYER_HPP

#include <memory>
#include <string>
#include <vector>
#include <cassert>
#include "Asciimon.hpp"
#include "PlayerMove.hpp"

class BattlePlayer {
private:
    std::string name;
    std::vector<Asciimon> party;
    std::vector<Asciimon>::iterator active;
public:
    using Ptr = std::unique_ptr<BattlePlayer>;

    BattlePlayer(std::string name, std::vector<Asciimon> party)
        : name(name), 
        party(party),
        active(std::begin(this->party)) {
        assert(!party.empty() && "A player cannot enter a battle with an empty party!");
    }

    virtual ~BattlePlayer() = default;

    virtual PlayerMove makeMove(const BattlePlayer& target) = 0;

    virtual void changeAsciimon(const BattlePlayer& target) = 0;

    virtual bool catchable() const {
        return false;
    }

    void addMember(Asciimon asciimon) {
        auto idx{active-std::begin(party)};
        party.push_back(asciimon);
        active = std::next(std::begin(party), idx);
    }

    void takeDamage(int damage) {
        auto& member{ getAsciimon() }; 
        member.setHealth(member.getHealth() - damage);
    }

    std::vector<Asciimon> getParty() const {
        return party;
    }

    Asciimon& getAsciimon() {
        return *active;
    }

    const Asciimon& getAsciimon() const {
        return *active;
    }

    bool isDefeated() const {
        return remainingParty().empty();
    }

    const std::string& getName() const {
        return name;
    }
protected:
    void switchAsciimon(std::vector<Asciimon>::const_iterator it) {
        assert(it != active && "Can't switch to same Asciimon!");

        active = std::next(std::begin(party), it - std::cbegin(party));
    }

    std::vector<std::vector<Asciimon>::const_iterator> remainingParty() const {
        std::vector<std::vector<Asciimon>::const_iterator> remaining;
        for (auto it{ std::begin(party) }; it != std::end(party); ++it) {
            if (it->getHealth() > 0) {
                remaining.push_back(it);
            }
        }
        return remaining;
    }
};

inline std::pair<std::string, float> healthRatio(const BattlePlayer& player) {
    const auto battleHealth{player.getAsciimon().getHealth()};
    const auto maxHealth{player.getAsciimon().getStatistics().getMaxHealth()};
    const auto ratio{static_cast<float>(battleHealth) / static_cast<float>(maxHealth)};
    return { std::to_string(battleHealth) + "/" + std::to_string(maxHealth), ratio };
}

#endif /* BATTLE_PLAYER_HPP */
