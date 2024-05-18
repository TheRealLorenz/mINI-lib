#include <gtest/gtest.h>

#include <fstream>

#include "../src/deserialize.h"

TEST(deserialize, deserializeFile) {
    std::ofstream file;
    file.open("prova.ini", std::ios_base::out | std::ios_base::trunc);
    file << "\
[Section 1]\n\
Param 1 = Value 1\n\
\n\
[Section 2]\n\
Param 2 = Value 2\n\
";
    file.close();

    ini::Config config = ini::deserialize("prova.ini");

    ASSERT_NE(config.find("Section 1"), config.end());
    auto section1 = config["Section 1"];
    ASSERT_NE(section1.find("Param 1"), section1.end());
    ASSERT_EQ(section1["Param 1"], "Value 1");

    ASSERT_NE(config.find("Section 2"), config.end());
    auto section2 = config["Section 2"];
    ASSERT_NE(section2.find("Param 2"), section2.end());
    ASSERT_EQ(section2["Param 2"], "Value 2");
}
