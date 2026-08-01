#include <SDL3/SDL.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_platform.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <iostream>
#include "Pet/pet.h"

//Cap Framerate to 60
const float targetFrameTime = 1000.0f / 60.0f;
Uint64 start;
Uint64 end;
Uint32 frameTime;


//Get Cursor's position
float cursorX = 0;
float cursorY = 0;

//The Pet object, duh!
Pet pet;


int main() {
    std::string platform = SDL_GetPlatform();
    if(platform == "Linux"){
        SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "x11");
    }
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

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
        start = SDL_GetTicks();
        //Make pet follow Cursor
        SDL_GetGlobalMouseState(&cursorX, &cursorY);
        pet.moveTo(cursorX, cursorY, frameTime);
        SDL_SetWindowPosition(window, pet.getPosX(), pet.getPosY());
        SDL_GetError();

        end = SDL_GetTicks();
        frameTime = end - start;

        if(frameTime < targetFrameTime){
            SDL_Delay(frameTime);
        }


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
