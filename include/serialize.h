#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_

#include <ostream>

#include "Config.h"

namespace ini {

void serialize(std::basic_ostream<char>& output, const Config& config);

}  // namespace ini

#endif  // _SERIALIZE_H_