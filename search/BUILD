load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
    deps = ["//dynamicprogramming:coinchanger"]
)

cc_library(
  name = "coinchanger",
  srcs = ["coinchanger.cc"],
  hdrs = ["coinchanger.h"],
)