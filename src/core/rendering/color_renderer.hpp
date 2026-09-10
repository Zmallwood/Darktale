#pragma once

namespace darktale {
    class color_renderer {
      public:
        void fill_rect(float x, float y, float width, float height,
                       color color = colors::k_black);
    };
}