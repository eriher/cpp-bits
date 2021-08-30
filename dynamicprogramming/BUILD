load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
  name = "coinchanger",
  srcs = ["coinchanger.cc"],
  hdrs = ["coinchanger.h"],
)

cc_test(
  name = "coinchanger_test",
  srcs = ["coinchanger_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//dynamicprogramming:coinchanger"
    ],
)

cc_library(
  name = "fibonacci",
  srcs = ["fibonacci.cc"],
  hdrs = ["fibonacci.h"],
)

cc_test(
  name = "fibonacci_test",
  srcs = ["fibonacci_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//dynamicprogramming:fibonacci"
    ],
)


cc_library(
  name = "knapsack",
  srcs = ["knapsack.cc"],
  hdrs = ["knapsack.h"],
)

cc_test(
  name = "knapsack_test",
  srcs = ["knapsack_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//dynamicprogramming:knapsack"
    ],
)