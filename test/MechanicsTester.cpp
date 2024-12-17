#include <gtest/gtest.h>
#include "../header/Asciimon.hpp"
#include "../header/BattleMechanics.hpp"



struct MechanicsFixture
{
    Asciimon a1;
    Asciimon a2;
    Move move;
    MechanicsFixture(Statistics s1, Statistics s2, float acc) 
        : a1("A1", ElementalType::FIRE, 0, s1),
        a2("A2", ElementalType::FIRE, 0, s2),
        move("Attack", "Test move", acc, 10) {

    }
    MechanicsFixture(float acc = 1.f) 
        : MechanicsFixture(Statistics{100, 10, 10, 10, 0}, Statistics{100, 10, 10, 10, 0}, acc) {

    }
};

TEST(BattleMechanicsSuite, GuranteedCritical)
{
    BattleMechanics bm(1.0);
    MechanicsFixture fixture;
    EXPECT_TRUE(bm.isCriticalMove(fixture.move, fixture.a1, fixture.a2));
}

TEST(BattleMechanicsSuite, NoCritical)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture;
    EXPECT_FALSE(bm.isCriticalMove(fixture.move, fixture.a1, fixture.a2));
}

TEST(BattleMechanicsSuite, GuranteedMove)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture(1.f);
    EXPECT_TRUE(bm.attemptMove(fixture.move, fixture.a1, fixture.a2));
}

TEST(BattleMechanicsSuite, NoMove)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture(0.f);
    EXPECT_FALSE(bm.attemptMove(fixture.move, fixture.a1, fixture.a2));
}

TEST(BattleMechanicsSuite, NormalMove)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture(1.f);
    EXPECT_LT(bm.computeMoveDamage(fixture.move, fixture.a1, fixture.a2, false), fixture.move.getPower());
}

TEST(BattleMechanicsSuite, CriticalMove)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture(1.f);
    EXPECT_GT(bm.computeMoveDamage(fixture.move, fixture.a1, fixture.a2, true), fixture.move.getPower());
}

TEST(BattleMechanicsSuite, VictoryExpBalanced)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture(1.f);
    EXPECT_EQ(bm.calculateVictoryExp(fixture.a1, fixture.a2), bm.calculateVictoryExp(fixture.a2, fixture.a1));
}

TEST(BattleMechanicsSuite, VictoryExpUnbalanced)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture(Statistics{0, 0, 0, 0, 10}, Statistics{0, 0, 0, 0, 1}, 1.f);
    EXPECT_LT(bm.calculateVictoryExp(fixture.a1, fixture.a2), bm.calculateVictoryExp(fixture.a2, fixture.a1));
}

TEST(BattleMechanicsSuite, GuaranteedNormalHit)
{
    BattleMechanics bm(0.0);
    MechanicsFixture fixture;
    HitDetails details{bm.attemptHit(fixture.move, fixture.a1, fixture.a2)};
    EXPECT_LE(details.getDamage(), fixture.move.getPower());
    EXPECT_NE(details.getMessage().find("uses the move"), std::string::npos);
    EXPECT_TRUE(details.getDetails().empty());
}

TEST(BattleMechanicsSuite, GuaranteedCriticalHit)
{
    BattleMechanics bm(1.0);
    MechanicsFixture fixture;
    HitDetails details{bm.attemptHit(fixture.move, fixture.a1, fixture.a2)};
    EXPECT_GT(details.getDamage(), fixture.move.getPower());
    EXPECT_NE(details.getMessage().find("uses the move"), std::string::npos);
    EXPECT_NE(details.getDetails().find("critical"), std::string::npos);
}

TEST(BattleMechanicsSuite, GuaranteedHitMiss)
{
    BattleMechanics bm(1.0);
    MechanicsFixture fixture(0.f);
    HitDetails details{bm.attemptHit(fixture.move, fixture.a1, fixture.a2)};
    EXPECT_EQ(details.getDamage(), 0);
    EXPECT_NE(details.getMessage().find("uses the move"), std::string::npos);
    EXPECT_NE(details.getDetails().find("evades"), std::string::npos);
}

