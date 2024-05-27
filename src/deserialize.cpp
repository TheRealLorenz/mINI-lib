#include "ini/deserialize.h"

#include <algorithm>

#include "ini/DeserializeError.h"
#include "utilstr/trim.h"

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
            throw new ini::DeserializeError(
                std::string("Invalid section header '") + buffer + "'");
        }

        std::string sectionName = buffer.substr(1, buffer.size() - 2);

        while (std::getline(input, buffer)) {
            if (!buffer.size()) continue;
            if (buffer[0] == '[') break;
            auto equal = std::find(buffer.begin(), buffer.end(), '=');

            if (equal == buffer.end() || equal == buffer.begin() ||
                equal == buffer.end() - 1) {
                throw new ini::DeserializeError(std::string("Invalid line '") +
                                                buffer + "'");
            }

            auto key = utilstr::rtrim(std::string(buffer.begin(), equal));
            auto value = utilstr::ltrim(std::string(equal + 1, buffer.end()));

            config[sectionName][key] = value;
        }
    }

    return config;
}

}  // namespace ini
