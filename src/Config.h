#ifndef _MINI_FILE_H_
#define _MINI_FILE_H_

#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> Section;
typedef std::unordered_map<std::string, Section> Config;

#endif  // _MINI_FILE_H_
