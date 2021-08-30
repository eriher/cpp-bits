load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
  name = "mergesort",
  hdrs = ["mergesort.h"],
)

cc_test(
  name = "mergesort_test",
  srcs = ["mergesort_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//sort:mergesort"
    ],
)

cc_library(
  name = "quicksort",
  hdrs = ["quicksort.h"],
)

cc_test(
  name = "quicksort_test",
  srcs = ["quicksort_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//sort:quicksort"
    ],
)

cc_library(
  name = "selectionsort",
  hdrs = ["selectionsort.h"],
)

cc_test(
  name = "selectionsort_test",
  srcs = ["selectionsort_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//sort:selectionsort"
    ],
)

cc_library(
  name = "bubblesort",
  hdrs = ["bubblesort.h"],
)

cc_test(
  name = "bubblesort_test",
  srcs = ["bubblesort_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//sort:bubblesort"
    ],
)