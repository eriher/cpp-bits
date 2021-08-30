load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
exports_files(["words.txt"])
cc_binary(
    name = "hangman",
    srcs = ["hangman.cc"],
    deps = ["//games/hangman:gamestate"],
    data = ["//games/hangman:words.txt"],
)

cc_library(
    name = "gamestate",
    srcs = ["game_state.cc"],
    hdrs = ["game_state.h"],
    data = ["//games/hangman:words.txt"],
)