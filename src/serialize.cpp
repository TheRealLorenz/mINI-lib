#include "ini/serialize.h"

#include <iostream>

namespace ini {

void serialize(std::basic_ostream<char>& output, const Config& config) {
    for (const auto& kv : config) {
        if (kv.first.empty()) {
            std::cerr << "Cannot write: Section name should not be empty"
                      << std::endl;
            return;
        }
        output << "[" << kv.first << "]\n";

        for (const auto& inner_kv : kv.second) {
            output << inner_kv.first << " = " << inner_kv.second << "\n";
        }

        output << "\n";
    }
}

}  // namespace ini
