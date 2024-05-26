#include "utilstr/split.h"

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
