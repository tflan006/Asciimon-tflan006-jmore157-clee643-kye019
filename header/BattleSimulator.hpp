#pragma once

#ifndef BATTLE_SIMULATOR_HPP
#define BATTLE_SIMULATOR_HPP

#include <functional>
#include "BattleMechanics.hpp"
#include "BattleResults.hpp"
#include "BattlePlayer.hpp"

using UI = std::function<void(const BattlePlayer&, const BattlePlayer&, std::string, std::string)>;

class BattleSimulator {
private:
    BattleMechanics mechanics;
public:
    BattleSimulator(BattleMechanics mechanics = BattleMechanics{ 1/6.f });

    std::pair<BattleResults, BattleResults> battle(BattlePlayer::Ptr player, BattlePlayer::Ptr opponent);

    std::pair<BattleResults, BattleResults> battle(BattlePlayer::Ptr player, BattlePlayer::Ptr opponent, UI ui);
};

#endif /* BATTLE_SIMULATOR_HPP */
