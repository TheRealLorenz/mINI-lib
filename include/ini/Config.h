#ifndef _MINI_FILE_H_
#define _MINI_FILE_H_

#include <map>
#include <string>
#include <utility>

template <typename T>
using pair_map = std::map<typename T::first_type, typename T::second_type>;

namespace ini {

typedef std::pair<std::string, std::string> Option;
typedef pair_map<Option> Options;

typedef std::pair<std::string, Options> Section;
typedef pair_map<Section> Config;

}  // namespace ini

#endif  // _MINI_FILE_H_
