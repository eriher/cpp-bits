#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "quicksort.h"
#include <vector>

using ::testing::ElementsAre;

namespace {
  TEST(QuickSortCopyTest, Empty) {
      std::vector<int> arr;
     ASSERT_EQ(QuickSort(arr).size(),0);
     ASSERT_EQ(QuickSort(arr),arr);
  }
  TEST(QuickSortCopyTest, OneElement) {
    
      std::vector<int> arr{5};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(5));
  }
  TEST(QuickSortCopyTest, TwoElement) {
    
      std::vector<int> arr{5,4};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(4,5));
  }
  TEST(QuickSortCopyTest, ThreeElements) {
    
      std::vector<int> arr{5,3,4};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(3,4,5));
  }
  TEST(QuickSortCopyTest, EvenElements) {
    
      std::vector<int> arr{5,4,3,2};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,3,4,5));
  }
  TEST(QuickSortCopyTest, OddElements) {
    
      std::vector<int> arr{5,3,4,2,1};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(1,2,3,4,5));
  }
  TEST(QuickSortCopyTest, AlreadySorted) {
    
      std::vector<int> arr{2,8,10,20,50,100};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,8,10,20,50,100));
  }
  TEST(QuickSortCopyTest, DuplicateElements) {
    
      std::vector<int> arr{2,8,10,20,50,2,8,2,10};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,2,2,8,8,10,10,20,50));
  }
  TEST(QuickSortCopyTest, SameElements) {
    
      std::vector<int> arr{2,2,2,2};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(2,2,2,2));
  }
  TEST(QuickSortCopyTest, NegativeElements) {
    
      std::vector<int> arr{12, 15, -23, -4 , 6, 10, -35, 28};
      auto sorted = QuickSort(arr);
      ASSERT_THAT(sorted,ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
  }
    TEST(QuickSortCopyTest, ReturnsCopy) {
    
      std::vector<int> arr{12, 15, -23, -4 , 6, 10, -35, 28};
      auto sorted = QuickSort(arr);
      arr.push_back(50);
      ASSERT_THAT(sorted,ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
  }
  TEST(QuickSortCopyTest, StringType){
      std::vector<std::string> arr{"a","b","c"};
      ASSERT_THAT(QuickSort(arr),ElementsAre("a", "b", "c"));
      arr.push_back("a");
      ASSERT_THAT(QuickSort(arr),ElementsAre("a", "a", "b", "c"));
      arr.push_back("adam");
      ASSERT_THAT(QuickSort(arr),ElementsAre("a", "a", "adam", "b", "c"));
  }

  TEST(QuickSortRefTest, Empty) {
    std::vector<int> arr;
    
    //ASSERT_EQ(false,true);
    QuickSort(arr,0,0);
    ASSERT_EQ(arr.size(),0);
    ASSERT_EQ(arr,arr);
  }
  TEST(QuickSortRefTest, OneElement) {
    
      std::vector<int> arr{5};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(5));
  }
  TEST(QuickSortRefTest, TwoElement) {
    
      std::vector<int> arr{5,4};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(4,5));
  }
  TEST(QuickSortRefTest, ThreeElements) {
    
      std::vector<int> arr{5,3,4};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(3,4,5));
  }
  TEST(QuickSortRefTest, EvenElements) {
    
      std::vector<int> arr{5,4,3,2};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(2,3,4,5));
  }
  TEST(QuickSortRefTest, OddElements) {
    
      std::vector<int> arr{5,3,4,2,1};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(1,2,3,4,5));
  }
  TEST(QuickSortRefTest, Alreadyarr) {
    
      std::vector<int> arr{2,8,10,20,50,100};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(2,8,10,20,50,100));
  }
  TEST(QuickSortRefTest, DuplicateElements) {
    
      std::vector<int> arr{2,8,10,20,50,2,8,2,10};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(2,2,2,8,8,10,10,20,50));
  }
  TEST(QuickSortRefTest, SameElements) {
    
      std::vector<int> arr{2,2,2,2};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(2,2,2,2));
  }
  TEST(QuickSortRefTest, NegativeElements) {
    
      std::vector<int> arr{12, 15, -23, -4 , 6, 10, -35, 28};
      QuickSort(arr,0,arr.size()-1);
      ASSERT_THAT(arr,ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
  }
  TEST(QuickSortRefTest, InPlace) {
    
      std::vector<int> arr{12, 15, -23, -4 , 6, 10, -35, 28};
      QuickSort(arr,0,arr.size()-1);
      arr.push_back(50);
      ASSERT_THAT(arr,ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28, 50));
  }
}