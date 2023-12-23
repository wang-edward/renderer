#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace render {

class Window {
    void initWindow();
    const int height;
    const int width;

    std::string windowName;
    GLFWwindow *window;
public:
    Window(int w, int h, std::string name);
    Window(const Window& other) = delete;
    Window &operator=(const Window& other) = delete;
    ~Window();
    bool shouldClose() { return glfwWindowShouldClose(window); }
    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
};

} // namespace render 
