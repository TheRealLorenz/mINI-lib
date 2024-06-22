#include "utilstr/trim.h"

#include <algorithm>
#include <string>
#include <vector>

namespace utilstr {

std::string rtrim(const std::string& s, const std::vector<char>& trimChars) {
    auto isTrimChar = [trimChars](const char c) {
        return std::find(trimChars.begin(), trimChars.end(), c) !=
               trimChars.end();
    };

    auto lastLegalChar =
        std::find_if(s.rbegin(), s.rend(), [isTrimChar](char c) {
            return !isTrimChar(c);
        }).base();

    return std::string(s.begin(), lastLegalChar);
}

std::string ltrim(const std::string& s, const std::vector<char>& trimChars) {
    auto isTrimChar = [trimChars](const char c) {
        return std::find(trimChars.begin(), trimChars.end(), c) !=
               trimChars.end();
    };

    auto firstLegalChar = std::find_if(
        s.begin(), s.end(), [isTrimChar](char c) { return !isTrimChar(c); });

    return std::string(firstLegalChar, s.end());
}

};  // namespace utilstr
