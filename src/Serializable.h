#ifndef _MINI_SERIALIZABLE_H_
#define _MINI_SERIALIZABLE_H_

#include "Config.h"

namespace ini {

class Serializable {
public:
    virtual Config serialize() const = 0;
};

}  // namespace ini

#endif  // _MINI_SERIALIZABLE_H_
