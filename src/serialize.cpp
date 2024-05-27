#include "ini/serialize.h"

#include "ini/SerializeError.h"

namespace ini {

void serializeOption(std::basic_ostream<char>& output, const Option& option) {
    output << option.first << " = " << option.second << "\n";
}

void serializeSection(std::basic_ostream<char>& output,
                      const Section& section) {
    if (section.first.empty()) {
        throw ini::SerializeError("Section name should not be empty");
    }
    output << "[" << section.first << "]\n";

    for (const auto& option : section.second) {
        serializeOption(output, option);
    }

    output << "\n";
}

void serialize(std::basic_ostream<char>& output, const Config& config) {
    for (const auto& section : config) {
        serializeSection(output, section);
    }
}

}  // namespace ini
