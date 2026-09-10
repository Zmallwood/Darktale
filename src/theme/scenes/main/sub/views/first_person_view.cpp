#include "first_person_view.hpp"
#include "core/core_game_objects/player.hpp"
#include "core/rendering/color_renderer.hpp"
#include "core/rendering/image_renderer.hpp"
#include "core/sdl_device/sdl_device.hpp"
#include "core/world_structure/tile.hpp"
#include "core/world_structure/world.hpp"
#include "core/world_structure/world_area.hpp"


namespace darktale {
    void first_person_view::render() {
        _<sdl_device>().clip(0.5f, 0.0f, 0.5f, 1.0f);

        _<color_renderer>().fill_rect(0.5f, 0.0f, 0.5f, 1.0f, colors::k_black);

        std::string ground_image_name;

        auto world_area{_<world>().current_world_area_};
        auto player_tile{world_area->get_tile(_<player>().position_)};
        auto ground_type{player_tile->ground_};

        switch (ground_type) {
        case get_hash("ground_grass"):
            ground_image_name = "ground_first_person_grass";
            break;
        case get_hash("ground_water"):
            ground_image_name = "ground_first_person_water";
            break;
        }

        _<image_renderer>().draw_image(
            ground_image_name, 0.5f + k_margin.x, 0.75f - k_margin.y,
            0.5f - 2 * k_margin.x, 0.25f - 2 * k_margin.y);

        _<sdl_device>().reset_clip();
    }
}