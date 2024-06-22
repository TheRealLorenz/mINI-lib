#ifndef _DESERIALIZE_H_
#define _DESERIALIZE_H_

#include <istream>

#include "Config.h"
#include "ini/Deserializable.h"

namespace ini {

void deserialize(std::basic_istream<char>& input, Deserializable& object);
Config deserialize(std::basic_istream<char>& input);
Section deserializeSection(std::basic_istream<char>& input);
Option deserializeOption(std::basic_istream<char>& input);

namespace stream {

std::string getLine(std::basic_istream<char>& input);

};  // namespace stream

}  // namespace ini

#endif  // _DESERIALIZE_H_
