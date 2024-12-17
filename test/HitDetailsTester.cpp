#include <gtest/gtest.h>
#include "../header/HitDetails.hpp"

TEST(HitDetailsSuite, Construction) {
    HitDetails details("", "", 0);
    EXPECT_EQ(details.getDamage(), 0);
    EXPECT_TRUE(details.getMessage().empty());
    EXPECT_TRUE(details.getMessage().empty());
}

TEST(HitDetailsSuite, NegativeDamage) {
    EXPECT_DEATH({
        HitDetails details("", "", -1);
    }, ".*");
}

TEST(HitDetailsSuite, NormalHit) {
    HitDetails details("Move ABC", "Critical!", 100);
    EXPECT_EQ(details.getDamage(), 100);
    EXPECT_EQ(details.getMessage(), "Move ABC");
    EXPECT_EQ(details.getDetails(), "Critical!");
}

