#ifndef INI_DESERIALIZEERROR_H_
#define INI_DESERIALIZEERROR_H_

#include "ini/Exception.h"

namespace ini {

class DeserializeError : public Exception {
public:
    explicit DeserializeError(const std::string& whatMsg)
        : ini::Exception("Couldn't deserialize: " + whatMsg) {}
};

};  // namespace ini

#endif  // INI_DESERIALIZEERROR_H_
