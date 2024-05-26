#ifndef _MINI_FILE_H_
#define _MINI_FILE_H_

#include <string>
#include <unordered_map>
#include <utility>

namespace ini {

typedef std::pair<std::string, std::string> Option;
typedef std::unordered_map<Option::first_type, Option::second_type> Options;

typedef std::pair<std::string, Options> Section;
typedef std::unordered_map<Section::first_type, Section::second_type> Config;

}  // namespace ini

#endif  // _MINI_FILE_H_
