load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
  name = "binarysearch",
  hdrs = ["binarysearch.h"],
)

cc_test(
  name = "binarysearch_test",
  srcs = ["binarysearch_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//search:binarysearch"
    ],
)

cc_library(
  name = "linearsearch",
  hdrs = ["linearsearch.h"],
)

cc_test(
  name = "linearsearch_test",
  srcs = ["linearsearch_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      "//search:linearsearch"
    ],
)