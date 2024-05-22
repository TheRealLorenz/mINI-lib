#include <fstream>
#include <iostream>

#include "Config.h"
#include "deserialize.h"
#include "serialize.h"

int main() {
    ini::Config config;

    for (int i = 0; i < 10; i++) {
        ini::Section section;

        section[std::to_string(i)] = std::to_string(i * i);

        config[std::string() + char(i + 65)] = section;
    }

    std::ofstream outputFile;
    outputFile.open("prova.ini", std::ios_base::out | std::ios_base::trunc);
    ini::serialize(outputFile, config);
    outputFile.close();

    std::ifstream inputFile;
    inputFile.open("prova.ini", std::ios_base::in);
    config = ini::deserialize(inputFile);
    inputFile.close();

    for (const auto& kv : config) {
        std::cout << "Section: " << kv.first << std::endl;

        for (const auto& inner_kv : kv.second) {
            std::cout << inner_kv.first << " = " << inner_kv.second
                      << std::endl;
        }
    }
}
