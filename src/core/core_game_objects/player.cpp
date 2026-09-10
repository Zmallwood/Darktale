#include "player.hpp"
#include "core/configuration/game_properties.hpp"

namespace darktale {
    player::player() {
        auto world_area_size{_<game_properties>().k_world_area_size_};

        position_ = {world_area_size.width / 2, world_area_size.height / 2};
    }

    void player::move_north() {
        position_.y -= 1;
    }

    void player::move_east() {
        position_.x += 1;
    }

    void player::move_south() {
        position_.y += 1;
    }

    void player::move_west() {
        position_.x -= 1;
    }
}