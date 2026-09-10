#include "tile_objects.hpp"
#include "object.hpp"

namespace darktale {
    void tile_objects::clear() {
        objects_.clear();
    }

    void tile_objects::add_object(std::string_view object_name,
                                  point position) {
        objects_.insert(
            {position, std::make_shared<object>(get_hash(object_name))});
    }
}