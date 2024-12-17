#include <gtest/gtest.h>
#include "../header/BattleResults.hpp"
#include "../header/ComputerPlayer.hpp"

TEST(BattleResultsSuite, Constructor)
{
    Trainer trainer{"trainer"};
    trainer.addAsciimon(Asciimon{"A", 0, ElementalType::DARK, 0, Statistics{100, 1,1,1,1}});
    trainer.addAsciimon(Asciimon{"B", 0, ElementalType::DARK, 0, Statistics{100, 1,1,1,1}});
    auto player{ ComputerPlayer::make(trainer) };
    auto ptr{player.get()};
    BattleResults results(BattleResults::LOSS, std::move(player));
    EXPECT_EQ(results.getResults(), BattleResults::LOSS);
    EXPECT_EQ(results.getPlayer(), ptr);
}

TEST(BattleResultsSuite, NullConstructor)
{
    EXPECT_DEATH({
        BattleResults results(BattleResults::LOSS, nullptr);
    }, ".*");
}

TEST(BattleResultsSuite, DamagedParty)
{
    Trainer trainer{"trainer"};
    trainer.addAsciimon(Asciimon{"A", 0, ElementalType::DARK, 0, Statistics{100, 1,1,1,1}});
    trainer.addAsciimon(Asciimon{"B", 0, ElementalType::DARK, 0, Statistics{100, 1,1,1,1}});
    auto player{ ComputerPlayer::make(trainer) };
    auto ptr{player.get()};
    BattleResults results(BattleResults::LOSS, std::move(player));
    for (auto member : results.getBattleParty()) {
        EXPECT_GT(member.getHealth(), 0);
    }
}

