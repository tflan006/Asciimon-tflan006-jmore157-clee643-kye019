#pragma once

#ifndef HUMAN_PLAYER_HPP
#define HUMAN_PLAYER_HPP

#include "BattlePlayer.hpp"
#include "Trainer.hpp"

class HumanPlayer : public BattlePlayer {
public:
    using Ptr = std::unique_ptr<HumanPlayer>;

    HumanPlayer(Trainer player);

    virtual ~HumanPlayer() override = default;

    virtual PlayerMove makeMove(const BattlePlayer& target) override;

    virtual void changeAsciimon(const BattlePlayer& target) override;

    static Ptr make(Trainer player);
};

#endif /* HUMAN_PLAYER_HPP */
