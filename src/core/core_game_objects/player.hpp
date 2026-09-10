#pragma once

namespace darktale {
    class player {
      public:
        player();

        void move_north();

        void move_east();

        void move_south();

        void move_west();

        point position_{0, 0};
        int ticks_last_movement_{0};
        float movement_speed_{4.0f};
        point destination_{-1, -1};
    };
}