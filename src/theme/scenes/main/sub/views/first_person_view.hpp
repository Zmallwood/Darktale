#pragma once

namespace darktale {
    class first_person_view {
      public:
        void render();

      private:
        static constexpr point_f k_margin{0.03f, 0.01f};
    };
}