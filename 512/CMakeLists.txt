cmake_minimum_required(VERSION 3.14)
project(MyRPC)

set(GOOGLETEST_VERSION 1.10.0)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(ROOT_PATH /usr1/l00596108/myRPC)

add_subdirectory(3rdLibs/googletest)
include_directories(3rdLibs/googletest/include)
include_directories(3rdLibs/googlemock/include)

include_directories(code/include)
add_subdirectory(code)
add_subdirectory(test)


if (BUILD_TEST)
    add_subdirectory(test)
endif()