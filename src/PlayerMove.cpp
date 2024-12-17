#include "../header/PlayerMove.hpp"

#include <iostream>

PlayerMove::PlayerMove(std::string message)
    : message(message),
    move(std::nullopt),
    fled(false) {
}

PlayerMove::PlayerMove(std::optional<Move> move)
    : message(std::nullopt),
    move(move),
    fled(false) {
}

PlayerMove::PlayerMove(bool fled)
    : message(std::nullopt),
    move(std::nullopt),
    fled(fled) {

}

std::optional<Move> PlayerMove::getMove() const {
    return move;
}

std::optional<std::string> PlayerMove::getMessage() const {
    return message;
}

bool PlayerMove::hasFled() const {
    return fled;
}
