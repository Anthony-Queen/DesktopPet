#include <SDL3/SDL.h>
#include <cstdlib>
#include <iostream>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cout << "Inititialization Failed: " << SDL_GetError();
        exit(1);
    }

    SDL_Window* window = SDL_CreateWindow("Pet", 400, 400, SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_NOT_FOCUSABLE);
    if(!window) {
        std::cout << "Encountered error creating window: " << SDL_GetError();
        SDL_Quit();
        return 1;
    }

    bool running = true;
    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
