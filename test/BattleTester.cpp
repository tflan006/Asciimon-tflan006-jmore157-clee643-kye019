#include <gtest/gtest.h>
#include "../header/BattleSimulator.hpp"
#include "../header/ComputerPlayer.hpp"
#include "../header/AsciimonCodex.hpp"

TEST(BattleSimulatorSuite, Constructor)
{
    EXPECT_NO_THROW({
        BattleSimulator simulator;
    });
}

TEST(BattleSimulatorSuite, Battle)
{
    AsciimonCodex codex;
    Trainer t1{"P1"};
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    Trainer t2{"P2"};
    t2.addAsciimon(codex.generateAsciimon(GRASS));
    BattleSimulator simulator;
    UI obj = [](const BattlePlayer& player, const BattlePlayer& opponent, std::string message, std::string details){};
    auto res{simulator.battle(ComputerPlayer::make(t1), ComputerPlayer::make(t2), obj)};
    EXPECT_NE(res.first.getResults(), res.second.getResults());
}
