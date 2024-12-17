#pragma once

#ifndef PLAYER_MOVE_HPP
#define PLAYER_MOVE_HPP

#include <string>
#include <optional>
#include "Move.hpp"

class PlayerMove {
private:
    std::optional<std::string> message;
    std::optional<Move> move;
    bool fled;
public:
    PlayerMove(std::string message);

    PlayerMove(std::optional<Move> move=std::nullopt);

    PlayerMove(bool fled);

    std::optional<Move> getMove() const;

    std::optional<std::string> getMessage() const;

    bool hasFled() const;
};

#endif /* PLAYER_MOVE_HPP */
