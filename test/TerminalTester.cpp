#include <gtest/gtest.h>
#include <sstream>
#include "../header/Terminal.hpp"
#include "../header/AsciimonCodex.hpp"

TEST(TerminalSuite, MainMenu)
{
    std::stringstream out;
    displayMainMenu(out);
    std::string str{out.str()};
    EXPECT_NE(str.find("ASCII DASHBOARD"), std::string::npos);
    EXPECT_NE(str.find("Quit"), std::string::npos);
    EXPECT_NE(str.find("Fight"), std::string::npos);
    EXPECT_NE(str.find("List"), std::string::npos);
}

TEST(TerminalSuite, AsciimonNames)
{
    Trainer trainer{""};
    trainer.addAsciimon(Asciimon{"Pikachu", ELECTRIC, 0, Statistics{1,1,1,1,1}});
    trainer.addAsciimon(Asciimon{"Charmander", FIRE, 0, Statistics{1,1,1,1,1}});
    std::stringstream out;
    displayAsciimonNames(trainer, out);
    std::string str{out.str()};
    EXPECT_NE(str.find("Pikachu"), std::string::npos);
    EXPECT_NE(str.find("Charmander"), std::string::npos);
}

TEST(TerminalSuite, AsciimonFightWin)
{
    AsciimonCodex codex;
    Trainer t1{""};
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    Trainer t2{""};
    t2.addAsciimon(codex.generateAsciimon(GRASS));
    std::stringstream out;
    BattleSimulator simulator;
    EXPECT_TRUE(fightTrainer(t1, t2, simulator, true, out));
    std::string str{out.str()};
    EXPECT_NE(str.find("fight"), std::string::npos);
}

TEST(TerminalSuite, AsciimonFightLoss)
{
    AsciimonCodex codex;
    Trainer t1{""};
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    Trainer t2{""};
    t2.addAsciimon(codex.generateAsciimon(GRASS));
    std::stringstream out;
    BattleSimulator simulator;
    EXPECT_FALSE(fightTrainer(t2, t1, simulator, true, out));
    std::string str{out.str()};
    EXPECT_NE(str.find("fight"), std::string::npos);
}

TEST(TerminalSuite, AsciimonFightEmpty)
{
    AsciimonCodex codex;
    Trainer t1{""};
    Trainer t2{""};
    std::stringstream out;
    BattleSimulator simulator;
    EXPECT_TRUE(fightTrainer(t2, t1, simulator, true, out));
}


TEST(TerminalSuite, UserChoiceQuit)
{
    AsciimonCodex codex;
    Trainer t1{""};
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    Trainer t2{""};
    t2.addAsciimon(codex.generateAsciimon(GRASS));
    std::stringstream out;
    BattleSimulator simulator;
    EXPECT_TRUE(processUserChoice('1', t1,t2,simulator, true,out));
}

TEST(TerminalSuite, UserChoiceFight)
{
    AsciimonCodex codex;
    Trainer t1{""};
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    Trainer t2{""};
    t2.addAsciimon(codex.generateAsciimon(GRASS));
    std::stringstream out;
    BattleSimulator simulator;
    processUserChoice('2', t1, t2, simulator, true, out);
    std::string str{out.str()};
    EXPECT_NE(str.find("fight"), std::string::npos);
}

TEST(TerminalSuite, UserChoiceDisplay)
{
    AsciimonCodex codex;
    Trainer t1{""};
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    t1.addAsciimon(codex.generateAsciimon(FIRE));
    Trainer t2{""};
    t2.addAsciimon(codex.generateAsciimon(GRASS));
    std::stringstream out;
    BattleSimulator simulator;
    processUserChoice('3', t1, t2, simulator, true, out);
    std::string str{out.str()};
    EXPECT_NE(str.find("TEAM"), std::string::npos);
}

TEST(TerminalSuite, UserChoiceInvalid)
{
    AsciimonCodex codex;
    Trainer t1{""};
    Trainer t2{""};
    std::stringstream out;
    BattleSimulator simulator;
    processUserChoice('x', t1, t2, simulator, true, out);
    std::string str{out.str()};
    EXPECT_NE(str.find("Invalid"), std::string::npos);
}

