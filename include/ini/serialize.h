#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_

#include <ostream>

#include "Config.h"
#include "ini/Serializable.h"

namespace ini {

void serialize(std::basic_ostream<char>& output, const Serializable& object);
void serialize(std::basic_ostream<char>& output, const Config& config);
void serializeSection(std::basic_ostream<char>& output, const Section& section);
void serializeOption(std::basic_ostream<char>& output, const Option& option);

}  // namespace ini

#endif  // _SERIALIZE_H_
