#include "utilstr/trim.h"

#include <algorithm>
#include <vector>

namespace utilstr {

void rtrim(std::string& s, const std::vector<char>& trimChars) {
    auto isTrimChar = [trimChars](const char c) {
        return std::find(trimChars.begin(), trimChars.end(), c) !=
               trimChars.end();
    };

    s.erase(std::find_if(s.rbegin(), s.rend(),
                         [isTrimChar](char c) { return !isTrimChar(c); })
                .base(),
            s.end());
}

void ltrim(std::string& s, const std::vector<char>& trimChars) {
    auto isTrimChar = [trimChars](const char c) {
        return std::find(trimChars.begin(), trimChars.end(), c) !=
               trimChars.end();
    };

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [isTrimChar](char c) {
                return !isTrimChar(c);
            }));
}

};  // namespace utilstr
