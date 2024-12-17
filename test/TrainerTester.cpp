#include "gtest/gtest.h"

#include <string>
#include "../header/Trainer.hpp"

//Trainer Tests
TEST(TrainerTests, TrainerNameTest){
    Trainer *b = new Trainer("Brock");
    EXPECT_EQ(b->getName(),"Brock");
}

TEST(TrainerTests, AddAsciimonTest){
    Trainer *b = new Trainer("Brock");
    Asciimon *pikachu = new Asciimon("Pikachu", ElementalType::ELECTRIC, 0, Statistics{140, 25, 40, 29, 1});

    b->addAsciimon(*pikachu);
    EXPECT_TRUE(b->getTeamCount() == 1);
}

TEST(TrainerTests, GetAsciimonTest){
    Trainer *b = new Trainer("Brock");
    Asciimon *pikachu = new Asciimon("Pikachu", ElementalType::ELECTRIC, 0, Statistics{140, 25, 40, 29, 1});
    b->addAsciimon(*pikachu);
    EXPECT_NO_THROW(b->getAsciimon(0));
}

TEST(TrainerTests, RemoveAsciimonTest){
    Trainer *b = new Trainer("Brock");
    Asciimon *pikachu = new Asciimon("Pikachu", ElementalType::ELECTRIC, 0, Statistics{140, 25, 40, 29, 1});
    b->addAsciimon(*pikachu);

    b->removeAsciimon(0);

    EXPECT_EQ(b->getTeamCount(),0);
}

TEST(TrainerTests, GetTeamCountTest){
    Trainer *b = new Trainer("Brock");
    Asciimon *pikachu = new Asciimon("Pikachu", ElementalType::ELECTRIC, 0, Statistics{140, 25, 40, 29, 1});
    b->addAsciimon(*pikachu);
    EXPECT_EQ(b->getTeamCount(),1);
}

TEST(TrainerTests, GetTeamTest){
    Trainer *b = new Trainer("Brock");
    Asciimon *pikachu = new Asciimon("Pikachu", ElementalType::ELECTRIC, 0, Statistics{140, 25, 40, 29, 1});
    b->addAsciimon(*pikachu);

    EXPECT_NO_THROW(b->getTeam());
}