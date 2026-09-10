#include "color_renderer.hpp"
#include "core/sdl_device/sdl_device.hpp"

namespace darktale {
    void color_renderer::fill_rect(float x, float y, float width, float height,
                                   color color) {
        auto canvas_size{get_canvas_size()};

        auto dest_x{static_cast<int>(x * canvas_size.width)};
        auto dest_y{static_cast<int>(y * canvas_size.height)};
        auto dest_width{static_cast<int>(width * canvas_size.width)};
        auto dest_height{static_cast<int>(height * canvas_size.height)};

        auto rect{SDL_Rect{dest_x, dest_y, dest_width, dest_height}};

        auto sdl_color{color.to_sdl_color()};

        SDL_SetRenderDrawColor(_<sdl_device>().renderer_.get(), sdl_color.r,
                               sdl_color.g, sdl_color.b, sdl_color.a);

        SDL_RenderFillRect(_<sdl_device>().renderer_.get(), &rect);
    }
}