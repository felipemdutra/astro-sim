#include <GLFW/glfw3.h>
#include <iostream>

#include "window.h"

static void framebuffer_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

namespace astro::graphics {

using namespace std;

Window* window_create(const int width, const int height, string title) {
    Window* w = new Window;
    w->width = width;
    w->height = height;
    w->title = title;

    if (!glfwInit()) {
        cerr << "Couldn't create window: Failed to initialize GLFW\n";
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);

    w->native_window = glfwCreateWindow(width, height, title.c_str(), 
            nullptr, nullptr);

    glfwMakeContextCurrent(w->native_window);
    
    glfwSetFramebufferSizeCallback(w->native_window, framebuffer_callback);

    return w;
}

void window_destroy(Window* w) {
    glfwDestroyWindow(w->native_window);
    delete w;
}

void swap_buffers(Window* w) {
    glfwSwapBuffers(w->native_window);
}

void poll_events() {
    glfwPollEvents();
}

bool window_should_close(Window *w) {
    return glfwWindowShouldClose(w->native_window);
}

} // namespace astro::graphics

