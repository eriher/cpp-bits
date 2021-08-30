#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "mergesort.h"
#include <vector>

using ::testing::ElementsAre;

namespace
{
    TEST(MergeSortCopyTest, Empty)
    {
        std::vector<int> arr;

        ASSERT_EQ(MergeSort(arr).size(), 0);
    }
    TEST(MergeSortCopyTest, OneElement)
    {

        std::vector<int> arr{5};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(5));
    }
    TEST(MergeSortCopyTest, TwoElement)
    {

        std::vector<int> arr{5, 4};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(4, 5));
    }
    TEST(MergeSortCopyTest, ThreeElements)
    {

        std::vector<int> arr{5, 3, 4};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(3, 4, 5));
    }
    TEST(MergeSortCopyTest, EvenElements)
    {

        std::vector<int> arr{5, 4, 3, 2};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 3, 4, 5));
    }
    TEST(MergeSortCopyTest, OddElements)
    {

        std::vector<int> arr{5, 3, 4, 2, 1};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(1, 2, 3, 4, 5));
    }
    TEST(MergeSortCopyTest, AlreadySorted)
    {

        std::vector<int> arr{2, 8, 10, 20, 50, 100};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 8, 10, 20, 50, 100));
    }
    TEST(MergeSortCopyTest, DuplicateElements)
    {

        std::vector<int> arr{2, 8, 10, 20, 50, 2, 8, 2, 10};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 2, 2, 8, 8, 10, 10, 20, 50));
    }
    TEST(MergeSortCopyTest, SameElements)
    {

        std::vector<int> arr{2, 2, 2, 2};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(2, 2, 2, 2));
    }
    TEST(MergeSortCopyTest, NegativeElements)
    {

        std::vector<int> arr{12, 15, -23, -4, 6, 10, -35, 28};
        auto sorted = MergeSort(arr);
        ASSERT_THAT(sorted, ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
    }
    TEST(MergeSortCopyTest, ReturnsCopy)
    {

        std::vector<int> arr{12, 15, -23, -4, 6, 10, -35, 28};
        auto sorted = MergeSort(arr);
        arr.push_back(50);
        ASSERT_THAT(sorted, ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
    }
    // Demonstrate some basic assertions.
    TEST(MergeSortRefTest, Empty)
    {
        std::vector<int> arr;
        MergeSort(arr, 0, 0);

        ASSERT_EQ(arr.size(), 0);
    }
    TEST(MergeSortRefTest, OneElement)
    {

        std::vector<int> arr{5};
        MergeSort(arr, 0, 0);
        ASSERT_THAT(arr, ElementsAre(5));
    }
    TEST(MergeSortRefTest, TwoElement)
    {

        std::vector<int> arr{5, 4};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(4, 5));
    }
    TEST(MergeSortRefTest, ThreeElements)
    {

        std::vector<int> arr{5, 3, 4};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(3, 4, 5));
    }
    TEST(MergeSortRefTest, EvenElements)
    {

        std::vector<int> arr{5, 4, 3, 2};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(2, 3, 4, 5));
    }
    TEST(MergeSortRefTest, OddElements)
    {

        std::vector<int> arr{5, 3, 4, 2, 1};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(1, 2, 3, 4, 5));
    }
    TEST(MergeSortRefTest, AlreadySorted)
    {

        std::vector<int> arr{2, 8, 10, 20, 50, 100};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(2, 8, 10, 20, 50, 100));
    }
    TEST(MergeSortRefTest, DuplicateElements)
    {

        std::vector<int> arr{2, 8, 10, 20, 50, 2, 8, 2, 10};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(2, 2, 2, 8, 8, 10, 10, 20, 50));
    }
    TEST(MergeSortRefTest, SameElements)
    {

        std::vector<int> arr{2, 2, 2, 2};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(2, 2, 2, 2));
    }
    TEST(MergeSortRefTest, NegativeElements)
    {

        std::vector<int> arr{12, 15, -23, -4, 6, 10, -35, 28};
        MergeSort(arr, 0, arr.size() - 1);
        ASSERT_THAT(arr, ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28));
    }
    TEST(MergeSortRefTest, Inplace)
    {

        std::vector<int> arr{12, 15, -23, -4, 6, 10, -35, 28};
        MergeSort(arr, 0, arr.size() - 1);
        arr.push_back(50);
        ASSERT_THAT(arr, ElementsAre(-35, -23, -4, 6, 10, 12, 15, 28, 50));
    }
}