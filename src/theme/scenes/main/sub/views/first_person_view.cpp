#include "first_person_view.hpp"
#include "core/configuration/game_properties.hpp"
#include "core/core_game_objects/player.hpp"
#include "core/rendering/color_renderer.hpp"
#include "core/rendering/image_renderer.hpp"
#include "core/sdl_device/sdl_device.hpp"
#include "core/world_structure/object.hpp"
#include "core/world_structure/tile.hpp"
#include "core/world_structure/tile_objects.hpp"
#include "core/world_structure/world.hpp"
#include "core/world_structure/world_area.hpp"

namespace darktale {
    void first_person_view::render() {
        _<sdl_device>().clip(0.5f, 0.0f, 0.5f, 1.0f);

        _<color_renderer>().fill_rect(1.0f - k_view_width_, 0.0f, k_view_width_,
                                      1.0f, colors::k_black);

        std::string ground_image_name;

        auto world_area{_<world>().current_world_area_};
        auto faced_tile{world_area->get_tile(_<player>().faced_tile_)};
        auto ground_type{faced_tile->ground_};

        switch (ground_type) {
        case get_hash("ground_grass"):
            ground_image_name = "ground_first_person_grass";
            break;
        case get_hash("ground_water"):
            ground_image_name = "ground_first_person_water";
            break;
        }

        _<image_renderer>().draw_image(
            ground_image_name, 1.0f - k_view_width_ + k_margin_.x,
            0.75f + k_margin_.y, k_view_width_ - 2 * k_margin_.x,
            0.25f - 2 * k_margin_.y);

        auto tile_units_width{_<game_properties>().k_tile_units_width_};

        auto objects{faced_tile->tile_objects_->objects_};

        for (auto entry : objects) {
            auto position{entry.first};
            auto object{entry.second};

            auto object_type{object->type_};

            auto image_width{0.3f};
            auto image_height{convert_width_to_height(image_width)};

            auto x_pos{position.x};
            auto y_pos{position.y};

            auto tile_width{k_view_width_ - 2 * k_margin_.x -
                            static_cast<float>(tile_units_width - y_pos) /
                                tile_units_width * k_view_width_ * 0.6f};
            auto tile_left{1.0f - k_view_width_ + k_margin_.x +
                           static_cast<float>(tile_units_width - y_pos) /
                               tile_units_width * k_view_width_ * 0.3f};

            auto base_x{tile_left + static_cast<float>(x_pos) /
                                        tile_units_width * tile_width};
            auto base_y{0.75f + k_margin_.y +
                        static_cast<float>(y_pos) / tile_units_width *
                            (0.25f - 2 * k_margin_.y)};

            auto image_x{base_x - image_width / 2.0f};
            auto image_y{base_y - image_height};

            _<image_renderer>().draw_image(object_type, image_x, image_y,
                                           image_width, image_height);
        }

        _<sdl_device>().reset_clip();
    }
}