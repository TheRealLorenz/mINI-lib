#include "ini/deserialize.h"

#include <algorithm>
#include <string>

#include "ini/Config.h"
#include "ini/DeserializeError.h"
#include "ini/EOFError.h"
#include "utilstr/trim.h"

namespace ini {

std::string getLine(std::basic_istream<char>& input) {
    std::string buffer;
    std::getline(input, buffer);

    while (input) {
        if (buffer.size() && buffer[0] != ';') {
            return buffer;
        }
        std::getline(input, buffer);
    }

    throw EOFError();
}

void putbackLine(std::basic_istream<char>& input, const std::string& line) {
    input.putback('\n');
    std::for_each(line.rbegin(), line.rend(),
                  [&input](const char c) { input.putback(c); });
}

Option parseOption(std::basic_istream<char>& input) {
    std::string line = getLine(input);

    auto equal = std::find(line.begin(), line.end(), '=');

    if (equal == line.end() || equal == line.begin() ||
        equal == line.end() - 1) {
        putbackLine(input, line);
        throw ini::DeserializeError(std::string("Invalid option '") + line +
                                    "'");
    }

    auto key = utilstr::rtrim(std::string(line.begin(), equal));
    auto value = utilstr::ltrim(std::string(equal + 1, line.end()));

    return {key, value};
}

Section parseSection(std::basic_istream<char>& input) {
    std::string line = getLine(input);

    if (line.size() < 3 || line[0] != '[' || line[line.size() - 1] != ']') {
        throw ini::DeserializeError(std::string("Invalid section header '") +
                                    line + "'");
    }

    std::string sectionName = line.substr(1, line.size() - 2);
    Options options;

    while (true) {
        try {
            Option option = parseOption(input);
            options.insert(option);
        } catch (const DeserializeError& e) {
            break;
        }
    }

    return {sectionName, options};
}

Config deserialize(std::basic_istream<char>& input) {
    Config config;

    while (true) {
        try {
            Section section = parseSection(input);
            config.insert(section);
        } catch (const EOFError& e) {
            break;
        }
    }

    return config;
}

}  // namespace ini
