#include "world_view.hpp"
#include "core/core_game_objects/player.hpp"
#include "core/rendering/image_renderer.hpp"
#include "core/sdl_device/sdl_device.hpp"
#include "core/world_structure/object.hpp"
#include "core/world_structure/object_stack.hpp"
#include "core/world_structure/tile.hpp"
#include "core/world_structure/world.hpp"
#include "core/world_structure/world_area.hpp"
#include "theme/scenes/main/sub/tile_hovering.hpp"
#include "core/configuration/game_properties.hpp"

namespace darktale {
    void world_view::render() {
        _<sdl_device>().clip(0.0f, 0.0f, 0.5f, 1.0f);

        auto world_area{_<world>().current_world_area_};

        auto player_tile{world_area->get_tile(_<player>().position_)};

        auto player_elevation{player_tile->elevation_};

        auto hovered_coordinate{_<tile_hovering>().hovered_coordinate_};

        auto faced_tile{_<player>().faced_tile_};

        auto tile_width{_<game_properties>().k_tile_width_};
        auto tile_height{convert_width_to_height(tile_width)};

        for (auto y = -6; y < 11 + 6; y++) {
            for (auto x = -6; x < 11 + 6; x++) {
                auto x_coordinate{_<player>().position_.x - 5 + x};
                auto y_coordinate{_<player>().position_.y - 5 + y};

                if (!world_area->is_valid_coordinate(x_coordinate,
                                                     y_coordinate)) {
                    continue;
                }

                auto tile{world_area->get_tile(x_coordinate, y_coordinate)};

                auto elevation{tile->elevation_};

                point coordinate_north{x_coordinate, y_coordinate - 1};
                point coordinate_east{x_coordinate + 1, y_coordinate};
                point coordinate_south{x_coordinate, y_coordinate + 1};
                point coordinate_west{x_coordinate - 1, y_coordinate};

                auto elevation_north{elevation};
                auto elevation_east{elevation};
                auto elevation_south{elevation};
                auto elevation_west{elevation};

                if (world_area->is_valid_coordinate(coordinate_north)) {
                    elevation_north =
                        world_area->get_tile(coordinate_north)->elevation_;
                }

                if (world_area->is_valid_coordinate(coordinate_east)) {
                    elevation_east =
                        world_area->get_tile(coordinate_east)->elevation_;
                }

                if (world_area->is_valid_coordinate(coordinate_south)) {
                    elevation_south =
                        world_area->get_tile(coordinate_south)->elevation_;
                }

                if (world_area->is_valid_coordinate(coordinate_west)) {
                    elevation_west =
                        world_area->get_tile(coordinate_west)->elevation_;
                }

                auto tile_x{0.25f - tile_width / 2 + x * tile_width / 2 -
                            y * tile_width / 2};

                auto tile_y{0.5f - 5.5f * tile_height + x * tile_height / 2 +
                            y * tile_height / 2 +
                            player_elevation * tile_height / 4};

                for (auto i = 0; i < elevation; i++) {
                    _<image_renderer>().draw_image(
                        "elevation", tile_x, tile_y + tile_height / 4,
                        tile_width, tile_height * 3 / 4);

                    tile_y -= tile_height / 4;
                }

                auto ground{tile->ground_};

                if (ground == get_hash("ground_water")) {
                    auto water_anim_index{
                        ((ticks() + 10 * x_coordinate * y_coordinate) % 900) /
                        600};

                    std::string ground_image_name{
                        "ground_water_" + std::to_string(water_anim_index)};

                    ground = get_hash(ground_image_name);
                }

                _<image_renderer>().draw_image(ground, tile_x, tile_y,
                                               tile_width, tile_height);

                if (elevation > elevation_north) {
                    _<image_renderer>().draw_image("elevation_edge_north",
                                                   tile_x, tile_y, tile_width,
                                                   tile_height);
                }

                if (elevation > elevation_east) {
                    _<image_renderer>().draw_image("elevation_edge_east",
                                                   tile_x, tile_y, tile_width,
                                                   tile_height);
                }

                if (elevation > elevation_south) {
                    _<image_renderer>().draw_image("elevation_edge_south",
                                                   tile_x, tile_y, tile_width,
                                                   tile_height);
                }

                if (elevation > elevation_west) {
                    _<image_renderer>().draw_image("elevation_edge_west",
                                                   tile_x, tile_y, tile_width,
                                                   tile_height);
                }

                if (x_coordinate == faced_tile.x && y_coordinate == faced_tile.y) {
                    _<image_renderer>().draw_image("faced_tile", tile_x,
                                                   tile_y, tile_width,
                                                   tile_height);
                }

                if (x_coordinate == hovered_coordinate.x &&
                    y_coordinate == hovered_coordinate.y) {

                    _<image_renderer>().draw_image("hovered_tile", tile_x,
                                                   tile_y, tile_width,
                                                   tile_height);
                }

                auto objects{tile->object_stack_->objects_};

                for (auto object : objects) {
                    auto object_type{object->type_};

                    _<image_renderer>().draw_image(object_type, tile_x,
                                                   tile_y - tile_height / 2,
                                                   tile_width, tile_height);
                }

                if (x_coordinate == _<player>().position_.x &&
                    y_coordinate == _<player>().position_.y) {
                    _<image_renderer>().draw_image("player", tile_x,
                                                   tile_y - tile_height / 2,
                                                   tile_width, tile_height);
                }
            }
        }

        _<sdl_device>().reset_clip();
    }
}