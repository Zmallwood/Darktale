#pragma once

namespace darktale {
    class object_stack;

    class tile {
      public:
        tile();

        int ground_{0};
        int elevation_{0};
        std::shared_ptr<object_stack> object_stack_;
    };
}