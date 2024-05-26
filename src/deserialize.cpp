#include "ini/deserialize.h"

#include <algorithm>

#include "../utilstr/include/trim.h"
#include "ini/Exception.h"

namespace ini {

Config deserialize(std::basic_istream<char>& input) {
    Config config;
    std::string buffer;

    std::getline(input, buffer);
    while (input) {
        if (!buffer.size() || buffer[0] == ';') {
            std::getline(input, buffer);
            continue;
        }

        if (buffer.size() < 3 || buffer[0] != '[' ||
            buffer[buffer.size() - 1] != ']') {
            throw new ini::Exception(
                std::string("Couldn't deserialize: Invalid section header '") +
                buffer + "'");
        }

        std::string sectionName = buffer.substr(1, buffer.size() - 2);

        while (std::getline(input, buffer)) {
            if (!buffer.size()) continue;
            if (buffer[0] == '[') break;
            auto equal = std::find(buffer.begin(), buffer.end(), '=');

            if (equal == buffer.end() || equal == buffer.begin() ||
                equal == buffer.end() - 1) {
                throw new ini::Exception(
                    std::string("Couldn't deserialize: Invalid line '") +
                    buffer + "'");
            }

            auto key = std::string(buffer.begin(), equal);
            auto value = std::string(equal + 1, buffer.end());
            rtrim(key);
            ltrim(value);

            config[sectionName][key] = value;
        }
    }

    return config;
}

}  // namespace ini
