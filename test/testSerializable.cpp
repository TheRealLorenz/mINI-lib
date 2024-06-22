#include <gtest/gtest.h>

#include <sstream>

#include "ini/Serializable.h"
#include "ini/serialize.h"

TEST(Serializable, Serialize) {
    struct ExampleConfig : public ini::Serializable {
        virtual ini::Config serialize() const override {
            ini::Config config;

            ini::Options videoOptions;
            videoOptions["width"] = std::to_string(width);
            videoOptions["height"] = std::to_string(height);
            videoOptions["scaleFactor"] = std::to_string(scaleFactor);
            config["video"] = videoOptions;

            ini::Options gameOptions;
            gameOptions["level"] = std::to_string(gameLevel);
            gameOptions["deathCount"] = std::to_string(deathCount);
            config["game"] = gameOptions;

            return config;
        }

        int width = 1920;
        int height = 1080;
        float scaleFactor = 1.2;

        int gameLevel = 3;
        int deathCount = 4;
    };

    ExampleConfig input;
    std::stringstream output;
    std::string expected = R"([game]
deathCount = 4
level = 3

[video]
height = 1080
scaleFactor = 1.200000
width = 1920

)";

    ini::serialize(output, input);

    ASSERT_EQ(output.str(), expected);
}
