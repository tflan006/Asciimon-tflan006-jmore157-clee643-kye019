#pragma once

#ifndef BATTLE_RESULTS_HPP
#define BATTLE_RESULTS_HPP

#include <vector>
#include "Asciimon.hpp"
#include "BattlePlayer.hpp"

class BattleResults {
public:
    enum Results {
        WON,
        FLED,
        LOSS
    };
private:
    Results results;
    BattlePlayer::Ptr player;
public:
    BattleResults(Results results, BattlePlayer::Ptr player);

    Results getResults() const;

    std::vector<Asciimon> getBattleParty() const;

    BattlePlayer* getPlayer();

    const BattlePlayer* getPlayer() const;
};

#endif /* BATTLE_RESULTS_HPP */
