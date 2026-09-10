#include "tile.hpp"
#include "object_stack.hpp"

namespace darktale {
    tile::tile() {
        object_stack_ = std::make_shared<object_stack>();
    }
}