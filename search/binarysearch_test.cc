#include <gtest/gtest.h>

#include "binarysearch.h"

#include <vector>

namespace {
    TEST(BinarySearchTest,Empty){
        std::vector<int> vec;
        ASSERT_EQ(BinarySearch(vec,0),-1);
    }
    TEST(BinarySearchTest,OneElementHit){
        std::vector<int> vec{0};
        ASSERT_EQ(BinarySearch(vec,0),0);
    }
    TEST(BinarySearchTest,OneElementMiss){
        std::vector<int> vec{1};
        ASSERT_EQ(BinarySearch(vec,0),-1);
    }    
    TEST(BinarySearchTest,ElementsHit){
        std::vector<int> vec{1,2,3,4,5,6,9,100,8,8};
        ASSERT_EQ(vec[BinarySearch(vec,8)],8);
    }
    TEST(BinarySearchTest,ElementsMiss){
        std::vector<int> vec{1,2,3,4,5,6,9,100,8,8};
        ASSERT_EQ(BinarySearch(vec,800),-1);
    }
}