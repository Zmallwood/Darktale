#pragma once

namespace darktale {
    class object;

    class tile_objects {
      public:
        void clear();

        void add_object(std::string_view object_name, point position = {5, 5});

        std::map<point, std::shared_ptr<object>> objects_;
    };
}