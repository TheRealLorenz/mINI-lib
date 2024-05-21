#include <gtest/gtest.h>

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../src/serialize.h"

std::vector<std::string> split(const std::string& s,
                               const std::string& pattern) {
    std::vector<std::string> parts;
    size_t baseIdx = 0;
    size_t patternIdx = 0;

    while ((patternIdx = s.find(pattern, baseIdx)) != std::string::npos) {
        parts.push_back(s.substr(baseIdx, patternIdx - baseIdx));
        baseIdx = patternIdx + pattern.size();
    }
    if (baseIdx != s.size()) {
        parts.push_back(s.substr(baseIdx));
    }

    return parts;
}

TEST(serialize, serializeFile) {
    ini::Config config;

    for (int i = 0; i < 10; i++) {
        ini::Section section;

        section[std::to_string(i)] = std::to_string(i * i);

        config[std::string() + char(i + 65)] = section;
    }
    ini::serialize("prova.ini", config);

    std::ifstream file;
    file.open("prova.ini", std::ios_base::in);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string serialized = buffer.str();

    auto sections = split(serialized, "\n\n");
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
