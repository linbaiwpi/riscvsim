cmake_minimum_required(VERSION 3.23)
project(test_glog)
set(USE_GLOG_CATKIN FALSE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GFLAG_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/gflags-2.2.2)
set(GLOG_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/glog-0.7.1)
set(GTEST_ROOT ${CMAKE_SOURCE_DIR}/thirdparty/googletest-1.15.2)
set(UTEST_ROOT ${CMAKE_SOURCE_DIR}/unittest)
set(SRC_ROOT ${CMAKE_SOURCE_DIR}/source)

include_directories(${GFLAG_ROOT}/build/include
                    ${GLOG_ROOT}/build
                    ${GTEST_ROOT}/googletest-1.15.2/include
                    ${CMAKE_SOURCE_DIR}/include)

set(gflags_DIR ${CMAKE_SOURCE_DIR}/thirdparty/gflags-2.2.2/build)
find_package(gflags REQUIRED PATHS ${CMAKE_SOURCE_DIR}/thirdparty/gflags-2.2.2 NO_DEFAULT_PATH)
set(glog_DIR ${CMAKE_SOURCE_DIR}/thirdparty/glog-0.7.1/build)
find_package(glog REQUIRED PATHS ${CMAKE_SOURCE_DIR}/thirdparty/glog-0.7.1 NO_DEFAULT_PATH)
find_package(Threads REQUIRED)

find_library(GTEST gtest ${CMAKE_SOURCE_DIR}/thirdparty/googletest-1.15.2/build/lib)
find_library(GTEST_MAIN gtest_main ${CMAKE_SOURCE_DIR}/thirdparty/googletest-1.15.2/build/lib)

# unit test
add_executable(test_glog ${UTEST_ROOT}/test_glog.cpp)
target_link_libraries(test_glog ${GTEST} ${GTEST_MAIN})
target_link_libraries(test_glog ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_glog glog::glog)

# main
add_executable(riscvsim ${SRC_ROOT}/main.cpp)
