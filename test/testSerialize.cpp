#include <gtest/gtest.h>

#include <algorithm>
#include <sstream>

#include "ini/serialize.h"
#include "utilstr/split.h"

TEST(serialize, serializeFile) {
    ini::Config config;

    for (int i = 0; i < 10; i++) {
        ini::Section section;

        section[std::to_string(i)] = std::to_string(i * i);

        config[std::string() + char(i + 65)] = section;
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
