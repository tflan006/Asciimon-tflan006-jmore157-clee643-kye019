#include <gtest/gtest.h>
#include "../header/ComputerPlayer.hpp"
#include "../header/Trainer.hpp"

namespace
{
    Asciimon asciimon(std::string name, int health, std::initializer_list<Move> moves) {
        Asciimon a{name, ElementalType::FIRE, 0, Statistics{health, 1,1,1,1}};
        for (auto move : moves) {
            a.addMove(move);
        }
        return a;
    }
    Trainer trainer(std::initializer_list<Asciimon> asciis) {
        Trainer trainer{"Trainer"};
        for (auto a : asciis) {
            trainer.addAsciimon(a);
        }
        return trainer;
    }
    Move accuracyMove{"accuracy", "", 1.0, 50};
    Move powerMove{"power", "", 0.5, 100};
    Move NULLMOVE{"","",0.f,0};
}


TEST(ComputerPlayerSuite, EmptyComputerTrainer) {
    EXPECT_DEATH({
        ComputerPlayer computer{trainer({})};
    }, ".*");
}

TEST(ComputerPlayerSuite, ValidComputerTrainer) {
    ComputerPlayer computer{trainer({ asciimon("A1", 100, {}) })};
    EXPECT_FALSE(computer.isDefeated());
    EXPECT_EQ(computer.getName(), "Trainer");
}

TEST(ComputerPlayerSuite, BigPartyTrainer) {
    ComputerPlayer computer{trainer({ asciimon("A1", 100, {}), asciimon("A2", 100, {}), asciimon("A3", 100, {}) })};
    EXPECT_EQ(computer.getParty().size(), 3);
}

TEST(ComputerPlayerSuite, SingleMoveTrainer) {
    ComputerPlayer computer{trainer({ asciimon("A", 100, {powerMove}) })};
    ComputerPlayer opp{trainer({ asciimon("B", 100, {}) })};
    EXPECT_TRUE(computer.makeMove(opp).getMove().has_value());
}

TEST(ComputerPlayerSuite, PowerMoveTrainer) {
    ComputerPlayer computer{trainer({ asciimon("A", 100, {powerMove, accuracyMove}) }), 1.0};
    ComputerPlayer opp{trainer({ asciimon("B", accuracyMove.getPower() + 1, {}) })};
    EXPECT_EQ(computer.makeMove(opp).getMove().value_or(NULLMOVE).getName(), powerMove.getName());
}

TEST(ComputerPlayerSuite, AccuracyMoveTrainer) {
    ComputerPlayer computer{trainer({ asciimon("A", 100, {powerMove, accuracyMove}) }), 1.0};
    ComputerPlayer opp{trainer({ asciimon("B", accuracyMove.getPower(), {}) })};
    EXPECT_EQ(computer.makeMove(opp).getMove().value_or(NULLMOVE).getName(), accuracyMove.getName());
}

TEST(ComputerPlayerSuite, RandomMoveTrainer) {
    ComputerPlayer computer{trainer({ asciimon("A", 100, {powerMove, accuracyMove}) }), 0.0};
    ComputerPlayer opp{trainer({ asciimon("B", accuracyMove.getPower(), {}) })};
    EXPECT_TRUE(computer.makeMove(opp).getMove().has_value());
}

TEST(ComputerPlayerSuite, AsciimonSwitch) {
    ComputerPlayer computer{trainer({ 
        asciimon("A", 0, {powerMove, accuracyMove}),
        asciimon("B", 0, {powerMove, accuracyMove}),
        asciimon("C", 100, {powerMove, accuracyMove}) 
    }), 0.0};
    ComputerPlayer opp{trainer({ asciimon("B", accuracyMove.getPower(), {}) })};
    computer.changeAsciimon(opp);
    EXPECT_EQ(computer.getAsciimon().getName(), "C");
}

