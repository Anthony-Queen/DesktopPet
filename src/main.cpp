#include <SDL3/SDL.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_platform.h>
#include <SDL3/SDL_timer.h>
#include <cstdlib>
#include <iostream>
#include "Pet/pet.h"

//Variables to calculate FPS
float prevTime;
float currentTime;
float deltaTime;
float frameTime;
const int Fps = 60;
const float frameDuration = 1000.0f / Fps;


//Get Cursor's position
float cursorX;
float cursorY;
//The Pet object, duh!
Pet pet;


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
        //Calculate FPS
        prevTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - prevTime) / 1000.0f;
        std::cout << "FPS: " << 1.0f / deltaTime << "\n";
        //Make pet follow Cursor
        SDL_GetGlobalMouseState(&cursorX, &cursorY);
        pet.moveTo(cursorX, cursorY, deltaTime);
        SDL_SetWindowPosition(window, static_cast<int>(pet.getPosX()), static_cast<int>(pet.getPosY()));
        SDL_GetError();

        frameTime = deltaTime - frameDuration;
        if(frameTime > 0){
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
