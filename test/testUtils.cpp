#include <gtest/gtest.h>

#include <sstream>

#include "ini/EOFError.h"
#include "ini/deserialize.h"

TEST(getLine, getLineNewline) {
    std::stringstream input;
    input << "FOO\n";

    ASSERT_EQ(ini::stream::getLine(input), "FOO");
    ASSERT_THROW(ini::stream::getLine(input), ini::EOFError);
}

TEST(getLine, getLineNoNewline) {
    std::stringstream input;
    input << "FOO";

    ASSERT_EQ(ini::stream::getLine(input), "FOO");
    ASSERT_THROW(ini::stream::getLine(input), ini::EOFError);
}

TEST(getLine, getLineIgnoreComment) {
    std::stringstream input;
    input << ";FOO\nBAR";

    ASSERT_EQ(ini::stream::getLine(input), "BAR");
    ASSERT_THROW(ini::stream::getLine(input), ini::EOFError);
}

TEST(getLine, getLineIgnoreEmptyLine) {
    std::stringstream input;
    input << "\n\nBAR\n\n";

    ASSERT_EQ(ini::stream::getLine(input), "BAR");
    ASSERT_THROW(ini::stream::getLine(input), ini::EOFError);
}

TEST(getLine, getLines) {
    std::stringstream input;
    input << ";FOO\n\nBAR\n\nBAZ\n\n";

    ASSERT_EQ(ini::stream::getLine(input), "BAR");
    ASSERT_EQ(ini::stream::getLine(input), "BAZ");
    ASSERT_THROW(ini::stream::getLine(input), ini::EOFError);
}
