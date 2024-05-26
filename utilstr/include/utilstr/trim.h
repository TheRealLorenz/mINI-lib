#include <string>
#include <vector>

namespace utilstr {

void rtrim(std::string& s, const std::vector<char>& trimChars = {' '});
void ltrim(std::string& s, const std::vector<char>& trimChars = {' '});

};  // namespace utilstr
