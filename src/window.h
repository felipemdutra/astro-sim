#include <GLFW/glfw3.h>
#include <string>

namespace astro::graphics {

struct Window {
    GLFWwindow* native_window;
    int width;
    int height;
    std::string title;
};

Window* window_create(const int width, const int height, std::string title);
void window_destroy(Window* w);

void swap_buffers(Window* w);
void poll_events();

bool window_should_close(Window* w);

}

