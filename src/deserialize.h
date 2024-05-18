#ifndef _DESERIALIZE_H_
#define _DESERIALIZE_H_

#include <string>

#include "Config.h"
#include "Deserializable.h"

namespace ini {

Config deserialize(const std::string& fileName);
void deserialize(const std::string& fileName, Deserializable& object);

}  // namespace ini

#endif  // _DESERIALIZE_H_
