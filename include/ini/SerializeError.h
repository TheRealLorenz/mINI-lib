#ifndef INI_SERIALIZEERROR_H_
#define INI_SERIALIZEERROR_H_

#include "ini/Exception.h"

namespace ini {

class SerializeError : public Exception {
public:
    explicit SerializeError(const std::string& whatMsg)
        : ini::Exception("Couldn't serialize: " + whatMsg) {}
};

};  // namespace ini

#endif  // INI_SERIALIZEERROR_H_
