#include <gtest/gtest.h>
#include "../header/PlayerMove.hpp"

TEST(PlayerMoveSuite, PlayerMessageConstructor) {
    PlayerMove pm(std::string{"message"});
    EXPECT_EQ(pm.getMessage().value(), "message");
    EXPECT_FALSE(pm.hasFled());
}

TEST(PlayerMoveSuite, PlayerMoveConstructor) {
    Move move{ "move", "", 0.f, 0 };
    PlayerMove pm(move);
    EXPECT_EQ(pm.getMove().value_or(Move{"", "", 0.f, 0}).getName(), move.getName());
    EXPECT_FALSE(pm.hasFled());
}

TEST(PlayerMoveSuite, PlayerFleeConstructor) {
    PlayerMove pm(true);
    EXPECT_TRUE(pm.hasFled());
}
