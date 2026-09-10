#pragma once

namespace darktale {
    class world_generator {
      public:
        void generate_new_world();

      private:
        void clear_with_grass();

        void generate_water();

        void generate_elevation();

        void generate_objects();
    };
}