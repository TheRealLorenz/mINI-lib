#include "ini/serialize.h"

#include "ini/SerializeError.h"

namespace ini {

void serializeOption(std::basic_ostream<char>& output, const Option& option) {
    if (option.first.empty()) {
        throw ini::SerializeError("Option name should not be empty");
    }

    output << option.first << " =";

    if (!option.second.empty()) {
        output << " " << option.second;
    }

    output << "\n";
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

void serialize(std::basic_ostream<char>& output, const Serializable& object) {
    serialize(output, object.serialize());
}

}  // namespace ini
