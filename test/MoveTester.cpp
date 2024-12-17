#include "gtest/gtest.h"

#include <string>
#include "../header/Move.hpp"

//Move Tests
TEST(MoveTests, NameTest) {
    Move *a = new Move("ASH","",1.0,5);
    EXPECT_EQ(a->getName(),"ASH");
}

TEST(MoveTests, DescriptionTest) {
    Move *a = new Move("ASH","become Handsome",1.0,5);
    EXPECT_EQ(a->getDescription(),"become Handsome");
}

TEST(MoveTests, AccuracyTest) {
    Move *a = new Move("ASH","",1.0,5);
    EXPECT_NEAR(a->getAccuracy(),1.0,0.1);
}

TEST(MoveTests, PowerTest) {
    Move *a = new Move("ASH","",1.0,5);
    EXPECT_EQ(a->getPower(),5);
}
