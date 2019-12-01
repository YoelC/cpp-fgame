#include <iostream>
#include "SDL2/Headers/SDL.h"
#include "player.h"
#include <sstream>

using namespace std;

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    SDL_KeyboardEvent keyboard_event;
    Player player;

    const int fps = 60;
    const int fps_delay = 1000/fps;

    int frame_start, frame_end;

    while (1) {
        frame_start = SDL_GetTicks();

        // Events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 0;
            }
        }

        // Player input
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_A]) {
            player.left();
        }
        if (state[SDL_SCANCODE_D]) {
            player.right();
        }
        if (state[SDL_SCANCODE_W]) {
            player.up();
        }
        if (state[SDL_SCANCODE_S]) {
            player.down();
        }
        // Calculating movement
        player.calculate_input();

        // Moving
        player.apply_gravity();
        player.move();

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        player.draw(renderer);
        SDL_RenderPresent(renderer);

        player.reset_variables();

        frame_end = SDL_GetTicks();
        int frame_time = frame_end - frame_start;
        if (fps_delay > frame_time) {
            SDL_Delay(fps_delay - frame_time);
        }

        if (frame_time == 0) {
            frame_time = 1;
        }
        auto frames = 1000 / frame_time;
        if (frames > fps) {
            frames = fps;
        }
        stringstream title_ss;
        title_ss << frames;
        SDL_SetWindowTitle(win, title_ss.str().c_str());
    }

    return 0;
}
