#include <gtest/gtest.h>

#include <string>

#include "utilstr/trim.h"

TEST(LTrim, TrimSpaces) {
    std::string input = "   Foo";
    utilstr::ltrim(input);

    ASSERT_EQ(input, "Foo");
}

TEST(LTrim, TrimChar) {
    std::string input = " =+ Foo";
    utilstr::ltrim(input, {' ', '+', '='});

    ASSERT_EQ(input, "Foo");
}

TEST(LTrim, NoTrim) {
    std::string input = "Foo";
    utilstr::ltrim(input);

    ASSERT_EQ(input, "Foo");
}

TEST(LTrim, TrimEmpty) {
    std::string input = "  ";
    utilstr::ltrim(input);

    ASSERT_EQ(input, "");
}

TEST(RTrim, TrimSpaces) {
    std::string input = "Foo   ";
    utilstr::rtrim(input);

    ASSERT_EQ(input, "Foo");
}

TEST(RTrim, TrimChar) {
    std::string input = "Foo =+ ";
    utilstr::rtrim(input, {' ', '+', '='});

    ASSERT_EQ(input, "Foo");
}

TEST(RTrim, NoTrim) {
    std::string input = "Foo";
    utilstr::rtrim(input);

    ASSERT_EQ(input, "Foo");
}

TEST(RTrim, TrimEmpty) {
    std::string input = "  ";
    utilstr::rtrim(input);

    ASSERT_EQ(input, "");
}
