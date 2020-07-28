workspace(name = "automotive_instrument_cluster")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")



http_archive(
    name = "can_utils",
    build_file = "//:can_utils.BUILD",
    sha256 = "68a5d7813fbf5fac1970cd316ffc67f50d3f9b42a047fffe225cc21a049fa37d",
    strip_prefix = "can-utils-2020.02.04",
    url = "https://github.com/linux-can/can-utils/archive/v2020.02.04.zip",
)
