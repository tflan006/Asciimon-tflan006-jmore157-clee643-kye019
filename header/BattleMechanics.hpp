#pragma once

#ifndef BATTLE_MECHANICS_HPP
#define BATTLE_MECHANICS_HPP

#include "HitDetails.hpp"
#include <random>

// forward declaration Asciimon
class Asciimon;
class Move;

class BattleMechanics {
private:
    float criticalChance;
public:
    BattleMechanics(float criticalChance);

    bool isCriticalMove(const Move& move, const Asciimon& attacker, const Asciimon& defender) const;

    bool attemptMove(const Move& move, const Asciimon& attacker, const Asciimon& defender) const;

    int computeMoveDamage(const Move& move, const Asciimon& attacker, const Asciimon& defender, bool isCritical) const;

    int calculateVictoryExp(const Asciimon& attacker, const Asciimon& defender) const;

    HitDetails attemptHit(const Move& move, const Asciimon& attacker, const Asciimon& defender) const;
};

#endif /* BATTLE_MECHANICS_HPP */
