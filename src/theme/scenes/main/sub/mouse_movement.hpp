#pragma once

namespace darktale {
    class mouse_movement {
      public:
        void update();

        void on_mouse_down(Uint8 button);
    };
}