#ifndef _DESERIALIZE_H_
#define _DESERIALIZE_H_

#include <string>

#include "Config.h"

namespace ini {

Config deserialize(const std::string& fileName);

}  // namespace ini

#endif  // _DESERIALIZE_H_
