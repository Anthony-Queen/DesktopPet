#pragma once
#include "getCursor.h"
#include <SDL3/SDL_mouse.h>

void getCursorX11(float &x, float &y){
    SDL_GetGlobalMouseState(&x, &y);
}

void getCursorHyprland(float &x, float &y){
    //Use Hyprland mouse socket
}

void getCursorWindows(float &x, float &y){
    //Code for Window
}

void getCursorCocoa(float& x, float& y){
    //MacOS Code
}

void setBackend(std::string Backend, void(*&getCursorPos)(float&, float&)){
    if(Backend=="x11"){
        getCursorPos = getCursorX11;
    }
    else if(Backend=="wayland"){
        //Use Hyprland socket
    }
    else if(Backend=="cocoa"){
        //MacOS code
    }
    else if(Backend=="windows"){
        //Windows code
    }
}
