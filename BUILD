load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "mp",
    srcs = [],
    hdrs = [
        "mp_list.h",
        "mp_plus.h",
        "mp_push_front.h",
        "mp_rename.h",
        "mp_size.h",
        "mp_transform.h",
    ],
    deps = [],
)

cc_binary(
    name = "tests",
    srcs = ["tests.cc"],
    deps = [
        ":mp",
    ],
)
