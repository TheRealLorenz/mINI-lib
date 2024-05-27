#include <gtest/gtest.h>

#include <algorithm>
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

TEST(serialize, serializeFile) {
    ini::Config config;

    for (int i = 0; i < 10; i++) {
        ini::Options options;

        options[std::to_string(i)] = std::to_string(i * i);

        config[std::string() + char(i + 65)] = options;
    }
    std::stringstream output;
    ini::serialize(output, config);
    std::string serialized = output.str();

    auto sections = utilstr::split(serialized, "\n\n");
    for (const auto& section : sections) {
        ASSERT_EQ(section[0], '[');
        auto closingBracket = std::find(section.begin(), section.end(), ']');
        ASSERT_NE(closingBracket, section.end());

        std::string sectionName =
            std::string(section.begin() + 1, closingBracket);
        ASSERT_EQ(sectionName.size(), 1);

        int sectionValue = (int)sectionName[0] - 65;
        auto newLine = std::find(section.begin(), section.end(), '\n');
        ASSERT_NE(newLine, section.end());

        ASSERT_EQ(std::string(newLine + 1, section.end()),
                  std::to_string(sectionValue) + " = " +
                      std::to_string(sectionValue * sectionValue));
    }
}
