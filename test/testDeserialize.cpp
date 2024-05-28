#include <gtest/gtest.h>

#include <sstream>

#include "ini/DeserializeError.h"
#include "ini/EOFError.h"
#include "ini/deserialize.h"

TEST(deserializeOption, deserializeFullOption) {
    std::stringstream input;
    input << "FOO = BAR";
    ini::Option expected{"FOO", "BAR"};

    ASSERT_EQ(ini::deserializeOption(input), expected);
}

TEST(deserializeOption, deserializeEmptyOption) {
    std::stringstream input;
    input << "FOO =";
    ini::Option expected{"FOO", ""};

    ASSERT_EQ(ini::deserializeOption(input), expected);
}

TEST(deserializeOption, deserializeInvalidOption) {
    std::stringstream input;

    input << "= BAR\n";
    ASSERT_THROW(ini::deserializeOption(input), ini::DeserializeError);
    ASSERT_EQ(input.str(), "= BAR\n");

    input.str("");
    input << " = BAR\n";
    ASSERT_THROW(ini::deserializeOption(input), ini::DeserializeError);
    ASSERT_EQ(input.str(), " = BAR\n");

    input.str("");
    input << "FOOBAR\n";
    ASSERT_THROW(ini::deserializeOption(input), ini::DeserializeError);
    ASSERT_EQ(input.str(), "FOOBAR\n");

    input.str("");
    ASSERT_THROW(ini::deserializeOption(input), ini::EOFError);
}

TEST(deserializeSection, deserializeFullSection) {
    std::stringstream input;
    input << "[Section 1]\nFOO = BAR\nBAZ=";

    ini::Options options;
    options.insert({"FOO", "BAR"});
    options.insert({"BAZ", ""});
    ini::Section expected{"Section 1", options};

    ASSERT_EQ(ini::deserializeSection(input), expected);
}

TEST(deserializeSection, deserializeEmptySection) {
    std::stringstream input;
    input << "[Section 1]";

    ini::Options options;
    ini::Section expected{"Section 1", options};

    ASSERT_EQ(ini::deserializeSection(input), expected);
}

TEST(deserializeSection, deserializeInvalidSection) {
    std::stringstream input;

    input << "[Section 1";
    ASSERT_THROW(ini::deserializeSection(input), ini::DeserializeError);

    input.str("");
    ASSERT_THROW(ini::deserializeSection(input), ini::EOFError);
}

TEST(deserialize, deserializeFile) {
    std::stringstream input;
    input << "\
[Section 1]\n\
Param 1 = Value 1\n\
\n\
[Section 2]\n\
Param 2 = Value 2\n\
";
    ini::Config config = ini::deserialize(input);

    ASSERT_NE(config.find("Section 1"), config.end());
    auto section1 = config["Section 1"];
    ASSERT_NE(section1.find("Param 1"), section1.end());
    ASSERT_EQ(section1["Param 1"], "Value 1");

    ASSERT_NE(config.find("Section 2"), config.end());
    auto section2 = config["Section 2"];
    ASSERT_NE(section2.find("Param 2"), section2.end());
    ASSERT_EQ(section2["Param 2"], "Value 2");
}
