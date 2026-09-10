#include "first_person_view.hpp"
#include "core/rendering/color_renderer.hpp"
#include "core/rendering/image_renderer.hpp"
#include "core/sdl_device/sdl_device.hpp"

namespace darktale {
    void first_person_view::render() {
        _<sdl_device>().clip(0.5f, 0.0f, 0.5f, 1.0f);

        _<color_renderer>().fill_rect(0.5f, 0.0f, 0.5f, 1.0f, colors::k_black);

        _<image_renderer>().draw_image(
            "ground_first_person_grass", 0.5f + k_margin.x, 0.75f - k_margin.y,
            0.5f - 2 * k_margin.x, 0.25f - 2 * k_margin.y);

        _<sdl_device>().reset_clip();
    }
}