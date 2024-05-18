#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_

#include <string>

#include "Config.h"
#include "Serializable.h"

namespace ini {

void serialize(const std::string& fileName, const Config& config);
void serialize(const std::string& fileName, const Serializable& object);

}  // namespace ini

#endif  // _SERIALIZE_H_
