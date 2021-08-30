#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "selectionsort.h"
#include <vector>

using ::testing::ElementsAre;

namespace
{
    TEST(SelectionSortTest, Empty)
    {
        std::vector<int> arr;
        ASSERT_EQ(SelectionSort(arr).size(), 0);
        ASSERT_EQ(SelectionSort(arr), arr);
    }
    TEST(SelectionSortTest, OneElement)
    {

        std::vector<int> arr{5};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(5));
    }
    TEST(SelectionSortTest, TwoElement)
    {

        std::vector<int> arr{5, 4};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(4, 5));
    }
    TEST(SelectionSortTest, ThreeElements)
    {

        std::vector<int> arr{5, 3, 4};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(3, 4, 5));
    }
    TEST(SelectionSortTest, EvenElements)
    {

        std::vector<int> arr{5, 4, 3, 2};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 3, 4, 5));
    }
    TEST(SelectionSortTest, OddElements)
    {
        std::vector<int> arr{5, 3, 4, 2, 1};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(1, 2, 3, 4, 5));
    }
    TEST(SelectionSortTest, AlreadySorted)
    {
        std::vector<int> arr{2, 8, 10, 20, 50, 100};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 8, 10, 20, 50, 100));
    }
    TEST(SelectionSortTest, DuplicateElements)
    {
        std::vector<int> arr{2, 8, 10, 20, 50, 2, 8, 2, 10};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 2, 2, 8, 8, 10, 10, 20, 50));
    }
    TEST(SelectionSortTest, SameElements)
    {
        std::vector<int> arr{2, 2, 2, 2};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 2, 2, 2));
    }
    TEST(SelectionSortTest, NegativeElements)
    {
        std::vector<int> arr{12, 15, -23, -4, 6, 10, -35, 28};
        auto sorted = SelectionSort(arr);
        ASSERT_THAT(sorted, ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
    }
    TEST(SelectionSortTest, ReturnsCopy)
    {
        std::vector<int> arr{12, 15, -23, -4, 6, 10, -35, 28};
        auto sorted = SelectionSort(arr);
        arr.push_back(50);
        ASSERT_THAT(sorted, ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
    }
}