#ifndef INI_EXCEPTION_H_
#define INI_EXCEPTION_H_

#include <string>

namespace ini {

class Exception : public std::runtime_error {
public:
    explicit Exception(const std::string& whatMsg)
        : std::runtime_error(whatMsg) {}
    virtual ~Exception() = 0;
};

inline Exception::~Exception() {}

}  // namespace ini

#endif  // INI_EXCEPTION_H_
