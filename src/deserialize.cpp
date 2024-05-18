#include "deserialize.h"

#include <fstream>
#include <iostream>

inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         [](char c) { return !std::isspace(c); })
                .base(),
            s.end());
}

inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    [](char c) { return !std::isspace(c); }));
}

Config deserialize(const std::string& fileName) {
    std::ifstream file;
    file.open(fileName, std::ios_base::in);
    Config config;

    std::string buffer;
    std::getline(file, buffer);
    while (file) {
        if (!buffer.size() || buffer[0] == ';') {
            std::getline(file, buffer);
            continue;
        }

        if (buffer.size() < 3 || buffer[0] != '[' ||
            buffer[buffer.size() - 1] != ']') {
            std::cerr << "Cannot read: Invalid section name" << std::endl;
            return config;
        }

        std::string sectionName = buffer.substr(1, buffer.size() - 2);

        while (std::getline(file, buffer)) {
            if (!buffer.size()) continue;
            if (buffer[0] == '[') break;
            auto equal = std::find(buffer.begin(), buffer.end(), '=');

            if (equal == buffer.end() || equal == buffer.begin() ||
                equal == buffer.end() - 1) {
                std::cerr << "Cannot read: Invalid line" << std::endl;
                return config;
            }

            auto key = std::string(buffer.begin(), equal);
            auto value = std::string(equal + 1, buffer.end());
            rtrim(key);
            ltrim(value);

            config[sectionName][key] = value;
        }
    }

    file.close();
    return config;
}
