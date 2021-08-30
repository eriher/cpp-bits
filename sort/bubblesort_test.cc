#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "bubblesort.h"
#include <vector>

using ::testing::ElementsAre;

namespace {
  TEST(BubbleSortTest, Empty) {
    std::vector<int> arr;
    ASSERT_EQ(BubbleSort(arr).size(),0);
    ASSERT_EQ(BubbleSort(arr),arr);
  }
    TEST(BubbleSortTest, OneElement) {

      std::vector<int> arr{5};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(5));
  }
  TEST(BubbleSortTest, TwoElement) {
    
      std::vector<int> arr{5,4};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(4,5));
  }
  TEST(BubbleSortTest, ThreeElements) {
    
      std::vector<int> arr{5,3,4};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(3,4,5));
  }
  TEST(BubbleSortTest, EvenElements) {
    
      std::vector<int> arr{5,4,3,2};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,3,4,5));
  }
  TEST(BubbleSortTest, OddElements) {
    
      std::vector<int> arr{5,3,4,2,1};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(1,2,3,4,5));
  }
  TEST(BubbleSortTest, AlreadySorted) {
    
      std::vector<int> arr{2,8,10,20,50,100};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,8,10,20,50,100));
  }
  TEST(BubbleSortTest, DuplicateElements) {
    
      std::vector<int> arr{2,8,10,20,50,2,8,2,10};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,2,2,8,8,10,10,20,50));
  }
  TEST(BubbleSortTest, SameElements) {
    
      std::vector<int> arr{2,2,2,2};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,2,2,2));
  }
  TEST(BubbleSortTest, NegativeElements) {
    
      std::vector<int> arr{12, 15, -23, -4 , 6, 10, -35, 28};
      auto sorted = BubbleSort(arr);
      ASSERT_THAT(sorted,ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
  }
    TEST(BubbleSortTest, ReturnsCopy) {
    
      std::vector<int> arr{12, 15, -23, -4 , 6, 10, -35, 28};
      auto sorted = BubbleSort(arr);
      arr.push_back(50);
      ASSERT_THAT(sorted,ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
  }
}