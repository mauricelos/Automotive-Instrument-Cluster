cc_library(
    name = "can_lib",
    srcs = ["src/can_data.cpp", "src/can_receiver.cpp"],
    hdrs = ["include/can_data.h", "include/can_receiver.h"],
    deps = ["@can_utils"],
    includes = ["include"],
)

cc_library(
    name = "websocket_lib",
    srcs = ["src/websocket_handler.cpp"],
    hdrs = ["include/websocket_handler.h"],
    includes = ["include"],
    copts = ["--std=c++14"],
)

cc_binary(
    name = "can_send",
    srcs = ["src/can_send.cpp"],
    args = ["vcan0", "42A#0201050000000000"],
    deps = ["@can_utils"],
)

cc_binary(
    name = "can_gen",
    srcs = ["src/can_gen.cpp"],
    #args = ["vcan0"],
    args = ["vcan0 -g 40 -I 42A -L 8 -D i -v -v"],
    deps = ["@can_utils"],
)

cc_binary(
    name = "main",
    srcs = ["src/main.cpp"],
    deps = [":can_lib", ":websocket_lib"],
    linkopts = ["-lpthread"],
    copts = ["--std=c++14"],
)

genrule(
    name = "run_can_gauge",
    srcs = [":main", "websocketd"],
    outs = ["websocket_log.txt"],
    cmd = "./websocketd --port=8080 $(location :main)",
)
