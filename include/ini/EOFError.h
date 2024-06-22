#ifndef INI_EOFERROR_H_
#define INI_EOFERROR_H_

#include "ini/DeserializeError.h"

namespace ini {

class EOFError : public DeserializeError {
public:
    EOFError() : DeserializeError("Reached EOF") {}
};

};  // namespace ini

#endif  // INI_EOFERROR_H_
