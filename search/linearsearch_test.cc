#include <gtest/gtest.h>

#include "linearsearch.h"

#include <vector>

namespace {
    TEST(LinearSearchTest,Empty){
        std::vector<int> vec;
        ASSERT_EQ(LinearSearch(vec,0),-1);
    }
    TEST(LinearSearchTest,OneElementHit){
        std::vector<int> vec{0};
        ASSERT_EQ(LinearSearch(vec,0),0);
    }
    TEST(LinearSearchTest,OneElementMiss){
        std::vector<int> vec{1};
        ASSERT_EQ(LinearSearch(vec,0),-1);
    }    
    TEST(LinearSearchTest,ElementsHit){
        std::vector<int> vec{1,2,3,4,5,6,9,100,8,8};
        ASSERT_EQ(LinearSearch(vec,8),8);
    }
    TEST(LinearSearchTest,ElementsMiss){
        std::vector<int> vec{1,2,3,4,5,6,9,100,8,8};
        ASSERT_EQ(LinearSearch(vec,800),-1);
    }
}