#pragma once

#include "window.hpp"
#include "pipeline.hpp"

namespace render {

class FirstApp {
    Window window{WIDTH, HEIGHT, "Hello world"};
    Pipeline pipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void run();
};

}
