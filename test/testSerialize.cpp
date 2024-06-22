#include <gtest/gtest.h>

#include <sstream>

#include "ini/SerializeError.h"
#include "ini/serialize.h"
#include "utilstr/split.h"

TEST(serializeOption, serializeFullOption) {
    std::stringstream output;
    ini::serializeOption(output, {"FOO", "BAR"});

    ASSERT_EQ(output.str(), "FOO = BAR\n");
}

TEST(serializeOption, serializeEmptyOption) {
    std::stringstream output;
    ini::serializeOption(output, {"FOO", ""});

    ASSERT_EQ(output.str(), "FOO =\n");
}

TEST(serializeOption, serializeInvalidOption) {
    std::stringstream output;

    ASSERT_THROW(ini::serializeOption(output, {"", "BAR"}),
                 ini::SerializeError);
}

TEST(serializeSection, serializeFullSection) {
    std::stringstream output;
    ini::Options options;
    options.insert({"FOO", "BAR"});
    options.insert({"BAZ", ""});
    ini::serializeSection(output, {"section1", options});

    ASSERT_EQ(output.str(), "[section1]\nBAZ =\nFOO = BAR\n\n");
}

TEST(serializeSection, serializeEmptySection) {
    std::stringstream output;
    ini::Options options;
    ini::serializeSection(output, {"section1", options});

    ASSERT_EQ(output.str(), "[section1]\n\n");
}

TEST(serializeSection, serializeInvalidSection) {
    std::stringstream output;
    ini::Options options;

    ASSERT_THROW(ini::serializeSection(output, {"", options}),
                 ini::SerializeError);
}

TEST(serialize, serializeFile) {
    ini::Config config;

    for (int i = 0; i < 5; i++) {
        ini::Options options;

        options[std::to_string(i)] = std::to_string(i * i);

        config[std::string() + char(i + 65)] = options;
    }
    std::stringstream output;
    ini::serialize(output, config);

    ASSERT_EQ(output.str(),
              R"([A]
0 = 0

[B]
1 = 1

[C]
2 = 4

[D]
3 = 9

[E]
4 = 16

)");
}
