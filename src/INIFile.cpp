#include "INIFile.h"

#include <fstream>
#include <iostream>

INIFile::INIFile(const std::string& fileName) : fileName(fileName) {}

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

std::unordered_map<std::string, INIFile::Section> INIFile::read() {
    std::ifstream file;
    file.open(fileName, std::ios_base::in);
    std::unordered_map<std::string, INIFile::Section> sections;

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
            return sections;
        }

        std::string sectionName = buffer.substr(1, buffer.size() - 2);

        while (std::getline(file, buffer)) {
            if (!buffer.size()) continue;
            if (buffer[0] == '[') break;
            auto equal = std::find(buffer.begin(), buffer.end(), '=');

            if (equal == buffer.end() || equal == buffer.begin() ||
                equal == buffer.end() - 1) {
                std::cerr << "Cannot read: Invalid line" << std::endl;
                return sections;
            }

            auto key = std::string(buffer.begin(), equal);
            auto value = std::string(equal + 1, buffer.end());
            rtrim(key);
            ltrim(value);

            sections[sectionName][key] = value;
        }
    }

    file.close();
    return sections;
}

void INIFile::write(
    const std::unordered_map<std::string, INIFile::Section>& sections) {
    std::ofstream file;
    file.open(fileName, std::ios_base::out | std::ios_base::trunc);

    for (const auto& kv : sections) {
        if (kv.first.empty()) {
            std::cerr << "Cannot write: Section name should not be empty"
                      << std::endl;
            return;
        }
        file << "[" << kv.first << "]\n";

        for (const auto& inner_kv : kv.second) {
            file << inner_kv.first << " = " << inner_kv.second << "\n";
        }

        file << "\n";
    }

    file.close();
}
