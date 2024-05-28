#ifndef _DESERIALIZE_H_
#define _DESERIALIZE_H_

#include <istream>

#include "Config.h"

namespace ini {

Config deserialize(std::basic_istream<char>& input);
Option deserializeOption(std::basic_istream<char>& input);

}  // namespace ini

#endif  // _DESERIALIZE_H_
