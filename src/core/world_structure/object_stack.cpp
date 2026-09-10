#include "object_stack.hpp"
#include "object.hpp"

namespace darktale {
    void object_stack::clear() {
        objects_.clear();
    }

    void object_stack::add_object(std::string_view object_name) {
        objects_.push_back(std::make_shared<object>(get_hash(object_name)));
    }
}