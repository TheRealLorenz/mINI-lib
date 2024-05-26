#include "ini/serialize.h"

#include "ini/Exception.h"

namespace ini {

void serialize(std::basic_ostream<char>& output, const Config& config) {
    for (const auto& kv : config) {
        if (kv.first.empty()) {
            throw new ini::Exception(
                "Couldn't serialize: Section name should not be empty");
        }
        output << "[" << kv.first << "]\n";

        for (const auto& inner_kv : kv.second) {
            output << inner_kv.first << " = " << inner_kv.second << "\n";
        }

        output << "\n";
    }
}

}  // namespace ini
