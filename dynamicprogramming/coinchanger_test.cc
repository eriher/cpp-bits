#include <gtest/gtest.h>

#include "coinchanger.h"

#include <vector>

namespace {
    TEST(CoinChangerTest,SingleCoin1){
        std::vector<int> coins{1};
        CoinChanger changer(coins);
        ASSERT_EQ(changer.howManyWays(5),1);
        ASSERT_EQ(changer.howManyWays(1),1);
        ASSERT_EQ(changer.howManyWays(16),1);
        ASSERT_EQ(changer.howManyWays(21),1);
    }
    TEST(CoinChangerTest,SingleCoin2){
        std::vector<int> coins{2};
        CoinChanger changer(coins);
        ASSERT_EQ(changer.howManyWays(1),0);
        ASSERT_EQ(changer.howManyWays(2),1);
        ASSERT_EQ(changer.howManyWays(3),0);
        ASSERT_EQ(changer.howManyWays(4),1);
        ASSERT_EQ(changer.howManyWays(5),0);
    }
    TEST(CoinChangerTest,MultiCoin1){
        std::vector<int> coins{1,2,3};
        CoinChanger changer(coins);
        ASSERT_EQ(changer.howManyWays(4),4);
        ASSERT_EQ(changer.howManyWays(5),5);
        ASSERT_EQ(changer.howManyWays(4),4);
        ASSERT_EQ(changer.howManyWays(1),1);
    }
    TEST(CoinChangerTest,MultiCoin2){
        std::vector<int> coins{2,5,3,6};
        CoinChanger changer(coins);
        ASSERT_EQ(changer.howManyWays(1),0);
        ASSERT_EQ(changer.howManyWays(2),1);
        ASSERT_EQ(changer.howManyWays(10),5);
        ASSERT_EQ(changer.howManyWays(2),1);
        ASSERT_EQ(changer.howManyWays(3),1);
    }
}