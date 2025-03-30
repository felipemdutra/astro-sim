#define WIDTH 800
#define HEIGHT 600

#include <string>

#include "window.h"

using namespace astro;

int main() {
    auto w = graphics::window_create(WIDTH, HEIGHT, "Astrophysics Sim");

    while (!graphics::window_should_close(w)) {

        // Render stuff here

        graphics::swap_buffers(w);
        graphics::poll_events();
    }

    graphics::window_destroy(w);
}

