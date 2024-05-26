#include <gtest/gtest.h>

#include <string>

#include "utilstr/split.h"

TEST(Split, SplitAroundSpaces) {
    std::string input = " This is a test ";
    std::vector<std::string> expected = {"This", "is", "a", "test"};

    ASSERT_EQ(utilstr::split(input), expected);
}

TEST(Split, SplitAroundPattern) {
    std::string input = "ABC==DEF==GHI==";
    std::vector<std::string> expected = {"ABC", "DEF", "GHI"};

    ASSERT_EQ(utilstr::split(input, "=="), expected);
}

TEST(Split, SplitEmpty) {
    std::vector<std::string> expected;

    ASSERT_EQ(utilstr::split(" "), expected);
    ASSERT_EQ(utilstr::split(""), expected);
}

TEST(Split, NoSplit) {
    std::string input = "ABCDEF";
    std::vector<std::string> expected = {"ABCDEF"};

    ASSERT_EQ(utilstr::split(input), expected);
}
