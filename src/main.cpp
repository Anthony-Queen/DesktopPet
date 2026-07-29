#include <SDL3/SDL.h>
#include <cstdlib>
#include <iostream>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cout << "Inititialization Failed: " << SDL_GetError();
        exit(1);
    }

    SDL_Window* window = SDL_CreateWindow("Pet", 150, 200, SDL_WINDOW_ALWAYS_ON_TOP);
    if(!window) {
        std::cout << "Encountered error creating window: " << SDL_GetError();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if(!renderer){
         std::cout << "Renderer creation failed: " << SDL_GetError();
         SDL_DestroyWindow(window);
         SDL_Quit();
         return 1;
    }
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);


    std::cout << "Window Created!\n";
    bool running = true;
    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
