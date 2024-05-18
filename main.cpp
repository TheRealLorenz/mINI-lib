#include <iostream>

#include "src/Config.h"
#include "src/deserialize.h"
#include "src/serialize.h"

int main() {
    ini::Config config;

    for (int i = 0; i < 10; i++) {
        ini::Section section;

        section[std::to_string(i)] = std::to_string(i * i);

        config[std::string() + char(i + 65)] = section;
    }

    ini::serialize("prova.ini", config);

    config = ini::deserialize("prova.ini");

    for (const auto& kv : config) {
        std::cout << "Section: " << kv.first << std::endl;

        for (const auto& inner_kv : kv.second) {
            std::cout << inner_kv.first << " = " << inner_kv.second
                      << std::endl;
        }
    }
}
