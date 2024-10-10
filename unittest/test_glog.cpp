#include <glog/logging.h>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    google::InitGoogleLogging(argv[0]); // Init GLog
    LOG(ERROR) << "There is error !!!";

    testing::InitGoogleTest(&argc, argv); // Init GTest
    return RUN_ALL_TESTS();
}

