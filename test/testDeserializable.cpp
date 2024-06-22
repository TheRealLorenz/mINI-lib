#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "ini/Deserializable.h"
#include "ini/deserialize.h"

TEST(Deserializable, Deserialize) {
    struct ExampleConfig : public ini::Deserializable {
        virtual void deserialize(ini::Config& config) override {
            width = std::stoi(config["video"]["width"]);
            height = std::stoi(config["video"]["height"]);
            scaleFactor = std::stof(config["video"]["scaleFactor"]);

            deathCount = std::stoi(config["game"]["deathCount"]);
            gameLevel = std::stoi(config["game"]["level"]);
        }

        int width = 0;
        int height = 0;
        float scaleFactor = 0;

        int gameLevel = 0;
        int deathCount = 0;
    };

    ExampleConfig config;
    std::stringstream input;
    input << R"([game]
deathCount = 4
level = 3

[video]
height = 1080
scaleFactor = 1.200000
width = 1920

)";

    ini::deserialize(input, config);

    ASSERT_EQ(config.width, 1920);
    ASSERT_EQ(config.height, 1080);

    ASSERT_EQ(config.deathCount, 4);
    ASSERT_EQ(config.gameLevel, 3);
    ASSERT_EQ(config.scaleFactor, 1.2f);
}
