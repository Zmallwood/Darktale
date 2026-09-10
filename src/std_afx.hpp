#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <filesystem>
#include <string>
#include <string_view>
#include <vector>
#include <set>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "common/singleton.hpp"
#include "common/sdl_deleter.hpp"
#include "common/get_hash.hpp"
#include "common/matter/geometry/point.hpp"
#include "common/matter/geometry/size.hpp"
#include "common/matter/geometry/point_f.hpp"
#include "common/matter/geometry/rect_f.hpp"
#include "common/string_utilities.hpp"
#include "common/file_path_utilities.hpp"
#include "common/canvas_utilities.hpp"
#include "common/time_utilities.hpp"
#include "common/number_utilities.hpp"
#include "common/mouse_utilities.hpp"