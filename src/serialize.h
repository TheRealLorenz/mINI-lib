#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_

#include <string>

#include "Config.h"

namespace ini {

void serialize(const std::string& fileName, const Config& config);

}  // namespace ini

#endif  // _SERIALIZE_H_
