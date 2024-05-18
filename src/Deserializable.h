#ifndef _MINI_DESERIALIZABLE_H_
#define _MINI_DESERIALIZABLE_H_

#include "Config.h"

namespace ini {

class Deserializable {
public:
    virtual void deserialize(const Config& config) = 0;
};

}  // namespace ini

#endif  // _MINI_DESERIALIZABLE_H_
