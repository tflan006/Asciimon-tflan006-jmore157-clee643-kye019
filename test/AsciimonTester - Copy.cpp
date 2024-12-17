#include <gtest/gtest.h>
#include "../header/Asciimon.hpp"
#include "../header/AsciimonCodex.hpp"


TEST(Asciimon, testName)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getName(), "Squirtle");
}

TEST(Asciimon, testType)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getType(), WATER);
}

TEST(Asciimon, testExp)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getExperience(), 0);
}

TEST(Asciimon, testExpGain)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.gainExperience(stats.getExpToLevel()), 1);
}

TEST(Asciimon, testExpGainMulti)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_GT(test.gainExperience(stats.getExpToLevel()*10+10), 1);
}

TEST(Asciimon, testHealth)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getHealth(), 100);
}

TEST(Asciimon, testAttack)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getStatistics().getAttack(), 75);
}

TEST(Asciimon, testDefense)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getStatistics().getDefense(), 125);
}

TEST(Asciimon, testSpeed)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getStatistics().getSpeed(), 50);
}

TEST(Asciimon, testLevel)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_EQ(test.getStatistics().getLevel(), 1);
}

TEST(Asciimon, testExpToLevel)
{
    Statistics stats(100, 75, 125, 50, 1);
    Asciimon test("Squirtle", stats.getMaxHealth(), WATER, 0, stats);
    EXPECT_GT(test.getStatistics().getExpToLevel(), 0);
}


TEST(RandomStats, maxHealthRangeTest)
{
    StatGenerator randomStats;
    Statistics stats = randomStats.generateStats();
    EXPECT_TRUE(100 <= stats.getMaxHealth() && stats.getMaxHealth() <= 200);
}

TEST(RandomStats, attackRangeTest)
{
    StatGenerator randomStats;
    Statistics stats = randomStats.generateStats();
    EXPECT_TRUE(50 <= stats.getAttack() && stats.getAttack() <= 100);
}

TEST(RandomStats, defenseRangeTest)
{
    StatGenerator randomStats;
    Statistics stats = randomStats.generateStats();
    EXPECT_TRUE(50 <= stats.getDefense() && stats.getDefense() <= 100);
}

TEST(RandomStats, speedRangeTest)
{
    StatGenerator randomStats;
    Statistics stats = randomStats.generateStats();
    EXPECT_TRUE(1 <= stats.getSpeed() && stats.getSpeed() <= 25);
}

TEST(AsciimonGeneration, fireTypeGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon(FIRE);
    EXPECT_EQ(test.getName(), "Charmander");
}

TEST(AsciimonGeneration, LightTypeGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon(LIGHT);
    EXPECT_EQ(test.getName(), "Snorlax");
}

TEST(AsciimonGeneration, WaterNameGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon("Squirtle");
    EXPECT_EQ(test.getType(), WATER);
}

TEST(AsciimonGeneration, DarkNameGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon("Meowth");
    EXPECT_EQ(test.getType(), DARK);
}

TEST(AsciimonGeneration, GrassNameGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon("Bulbasaur");
    EXPECT_EQ(test.getType(), GRASS);
}

TEST(AsciimonGeneration, GroundNameGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon("Diglet");
    EXPECT_EQ(test.getType(), GROUND);
}

TEST(AsciimonGeneration, IceNameGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon("Articuno");
    EXPECT_EQ(test.getType(), ICE);
}

TEST(AsciimonGeneration, DragonNameGeneration)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon("Dragonite");
    EXPECT_EQ(test.getType(), DRAGON);
}

TEST(AsciimonGeneration, ElectricNameGenerator)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateAsciimon("Pikachu");
    EXPECT_EQ(test.getType(), ELECTRIC);
}

TEST(AsciimonGeneration, WaterToAsciimon)
{
    AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::WATER), "Squirtle");
}

TEST(AsciimonGeneration, FireToAsciimon)
{
   AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::FIRE), "Charmander");
}

TEST(AsciimonGeneration, GroundToAsciimon)
{
    AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::GROUND), "Diglet");
}

TEST(AsciimonGeneration, GrassToAsciimon)
{
   AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::GRASS), "Bulbasaur");
}

TEST(AsciimonGeneration, ElectricToAsciimon)
{
   AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::ELECTRIC), "Pikachu");
}

TEST(AsciimonGeneration, IceToAsciimon)
{
    AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::ICE), "Articuno");
}

TEST(AsciimonGeneration, DragonToAsciimon)
{
    AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::DRAGON), "Dragonite");
}

TEST(AsciimonGeneration, DarkToAsciimon)
{
    AsciimonCodex codex;
    EXPECT_EQ(codex.TypetoName(ElementalType::DARK), "Meowth");
}

TEST(AsciimonGeneration, RandomGenerationOne)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateRandomAsciimon();
    EXPECT_EQ(test.getMoveSet().size(), 3);
}

TEST(AsciimonGeneration, RandomGenerationTwo)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateRandomAsciimon();
    EXPECT_EQ(test.getMoveSet().size(), 3);
}

TEST(AsciimonGeneration, RandomGenerationThree)
{
    AsciimonCodex codex;
    Asciimon test = codex.generateRandomAsciimon();
    EXPECT_EQ(test.getMoveSet().size(), 3);
}

