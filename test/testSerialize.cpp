#include <gtest/gtest.h>

#include <sstream>

#include "ini/serialize.h"
#include "utilstr/split.h"

TEST(serialize, serializeFile) {
    ini::Config config;

    for (int i = 0; i < 5; i++) {
        ini::Options options;

        options[std::to_string(i)] = std::to_string(i * i);

        config[std::string() + char(i + 65)] = options;
    }
    std::stringstream output;
    ini::serialize(output, config);

    ASSERT_EQ(output.str(),
              R"([A]
0 = 0

[B]
1 = 1

[C]
2 = 4

[D]
3 = 9

[E]
4 = 16

)");
}
