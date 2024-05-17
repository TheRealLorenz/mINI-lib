#include <iostream>
#include <unordered_map>

#include "src/INIFile.h"

int main() {
    INIFile file("prova.ini");
    std::unordered_map<std::string, INIFile::Section> values;

    for (int i = 0; i < 10; i++) {
        INIFile::Section section;

        section[std::to_string(i)] = std::to_string(i * i);

        values[std::string() + char(i + 65)] = section;
    }

    file.write(values);

    values = file.read();

    for (const auto& kv : values) {
        std::cout << "Section: " << kv.first << std::endl;

        for (const auto& inner_kv : kv.second) {
            std::cout << inner_kv.first << " = " << inner_kv.second
                      << std::endl;
        }
    }
}
