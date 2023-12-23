#include "first_app.hpp"

using namespace std;

namespace render {

void FirstApp:: run() {
    while (!window.shouldClose()) {
        glfwPollEvents();
    }
}
} // namespace render
