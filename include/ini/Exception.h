#include <string>

namespace ini {

class Exception : public std::runtime_error {
public:
    Exception(const std::string& whatMsg) : std::runtime_error(whatMsg) {}
};

}  // namespace ini
