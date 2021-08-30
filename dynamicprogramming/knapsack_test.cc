#include <gtest/gtest.h>

#include "knapsack.h"

namespace {
    TEST(KnapsackTest, Capacity){
        Knapsack knapsack(10);
        ASSERT_EQ(knapsack.getCapacity(),10);
    }
    TEST(KnapsackTest, OneItem){
        Knapsack knapsack(10);
        std::vector<std::pair<int,int>> items{std::make_pair(10,10)};
        ASSERT_EQ(knapsack.storeItems(items),10);
    }
    TEST(KnapsackTest, TwoItems){
        Knapsack knapsack(10);
        std::vector<std::pair<int,int>> items{std::make_pair(5,10),std::make_pair(5,8)};
        ASSERT_EQ(knapsack.storeItems(items),18);
    }
    TEST(KnapsackTest, OverCapacity){
        Knapsack knapsack(10);
        std::vector<std::pair<int,int>> items{std::make_pair(15,10)};
        ASSERT_EQ(knapsack.storeItems(items),0);
    }
    TEST(KnapsackTest, BestOfTwo){
        Knapsack knapsack(10);
        std::vector<std::pair<int,int>> items{std::make_pair(10,25),std::make_pair(10,20)};
        ASSERT_EQ(knapsack.storeItems(items),25);
        //std::vector<std::pair<int,int>> items{std::make_pair(10,20),std::make_pair(10,25)};
        //std::reverse(items.first(),items.end());
        ASSERT_EQ(knapsack.storeItems(items),25);
    }
    TEST(KnapsackTest, ManyItems){
        Knapsack knapsack(10);
        std::vector<std::pair<int,int>> items{std::make_pair(10,25),std::make_pair(10,20),std::make_pair(1,2),std::make_pair(4,7)};
        ASSERT_EQ(knapsack.storeItems(items),25);
        //std::vector<std::pair<int,int>> items{std::make_pair(10,20),std::make_pair(10,25)};
        //std::reverse(items.first(),items.end());
        ASSERT_EQ(knapsack.storeItems(items),25);
    }
}
