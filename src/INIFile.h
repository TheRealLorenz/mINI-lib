#ifndef _MINI_INI
#define _MINI_INI

#include <string>
#include <unordered_map>

class INIFile {
public:
    typedef std::unordered_map<std::string, std::string> Section;

    explicit INIFile(const std::string& fileName);
    INIFile(const INIFile& other) = delete;
    INIFile& operator=(const INIFile& other) = delete;

    std::unordered_map<std::string, Section> read();

    void write(const std::unordered_map<std::string, Section>& sections);

private:
    std::string fileName;
};

#endif  // _MINI_INI
