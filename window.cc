#include "window.hpp"
#include <stdexcept>

using namespace std;

namespace render {

Window:: Window(int width, int height, string windowName): width{width}, height{height}, windowName{windowName} {
    initWindow();
}

Window:: ~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window:: initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

void Window:: createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw runtime_error{"Failed to create window surface"};
    }
}


} // namespace render
