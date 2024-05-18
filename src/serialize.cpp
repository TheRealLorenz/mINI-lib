#include "serialize.h"

#include <fstream>
#include <iostream>
#include <string>

namespace ini {

void serialize(const std::string& fileName, const Serializable& object) {
    serialize(fileName, object.serialize());
}

void serialize(const std::string& fileName, const Config& config) {
    std::ofstream file;
    file.open(fileName, std::ios_base::out | std::ios_base::trunc);

    for (const auto& kv : config) {
        if (kv.first.empty()) {
            std::cerr << "Cannot write: Section name should not be empty"
                      << std::endl;
            return;
        }
        file << "[" << kv.first << "]\n";

        for (const auto& inner_kv : kv.second) {
            file << inner_kv.first << " = " << inner_kv.second << "\n";
        }

        file << "\n";
    }

    file.close();
}

}  // namespace ini
