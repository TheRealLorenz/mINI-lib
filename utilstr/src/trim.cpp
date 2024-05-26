#include "utilstr/trim.h"

#include <algorithm>

namespace utilstr {

void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         [](char c) { return !std::isspace(c); })
                .base(),
            s.end());
}

void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    [](char c) { return !std::isspace(c); }));
}

};  // namespace utilstr
