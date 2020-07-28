package(default_visibility = ["//visibility:public"])

cc_library(
    name = "can_utils_lib",
    hdrs = ["lib.h", "terminal.h"],
    srcs = ["lib.c"],
    includes = [""],
)

cc_library(
    name = "can_utils",
    hdrs = glob(["include/linux/*.h", "include/linux/can/*.h"]),
    includes = ["include"],
    deps = [":can_utils_lib"],
)