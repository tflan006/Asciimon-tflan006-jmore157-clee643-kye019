#pragma once

#ifndef COMPUTER_PLAYER_HPP
#define COMPUTER_PLAYER_HPP

#include "BattlePlayer.hpp"
#include "Trainer.hpp"

class ComputerPlayer : public BattlePlayer {
private:
    double intelligence;
    bool isCatchable;
public:
    using Ptr = std::unique_ptr<ComputerPlayer>;

    ComputerPlayer(Trainer trainer, double intelligence=0.5);

    virtual ~ComputerPlayer() override = default;

    virtual PlayerMove makeMove(const BattlePlayer& target) override;

    virtual void changeAsciimon(const BattlePlayer& target) override;

    virtual bool catchable() const override;

    static Ptr make(Trainer trainer);

    static Ptr make(Asciimon asciimon);
};

#endif /* COMPUTER_PLAYER_HPP */
