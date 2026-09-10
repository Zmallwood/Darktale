#pragma once

namespace darktale {
    class object;

    class object_stack {
      public:
        void clear();

        void add_object(std::string_view object_name);

        std::vector<std::shared_ptr<object>> objects_;
    };
}