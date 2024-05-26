#include <gtest/gtest.h>

#include <string>

#include "utilstr/trim.h"

TEST(LTrim, TrimSpaces) {
    std::string input = "   Foo";

    ASSERT_EQ(utilstr::ltrim(input), "Foo");
}

TEST(LTrim, TrimChar) {
    std::string input = " =+ Foo";

    ASSERT_EQ(utilstr::ltrim(input, {' ', '+', '='}), "Foo");
}

TEST(LTrim, NoTrim) {
    std::string input = "Foo";

    ASSERT_EQ(utilstr::ltrim(input), "Foo");
}

TEST(LTrim, TrimEmpty) {
    std::string input = "  ";

    ASSERT_EQ(utilstr::ltrim(input), "");
}

TEST(RTrim, TrimSpaces) {
    std::string input = "Foo   ";

    ASSERT_EQ(utilstr::rtrim(input), "Foo");
}

TEST(RTrim, TrimChar) {
    std::string input = "Foo =+ ";

    ASSERT_EQ(utilstr::rtrim(input, {' ', '+', '='}), "Foo");
}

TEST(RTrim, NoTrim) {
    std::string input = "Foo";

    ASSERT_EQ(utilstr::rtrim(input), "Foo");
}

TEST(RTrim, TrimEmpty) {
    std::string input = "  ";

    ASSERT_EQ(utilstr::rtrim(input), "");
}
