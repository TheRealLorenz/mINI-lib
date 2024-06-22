#include <string>
#include <vector>

namespace utilstr {

std::string rtrim(const std::string& s,
                  const std::vector<char>& trimChars = {' '});
std::string ltrim(const std::string& s,
                  const std::vector<char>& trimChars = {' '});

};  // namespace utilstr
