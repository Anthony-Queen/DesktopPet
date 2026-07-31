#include "pet.h"
#include <SDL3/SDL_video.h>
#include <cmath>

void Pet::moveTo(float cursorX, float cursorY, float deltaTime) {
    float deltaX = cursorX - posX;
    float deltaY = cursorY - posY;
    //If pet is near cursor then stop moving, otherwise keep on going
    if(deltaY < 0.2 and deltaX < 0.2){
        currentState = IDLE;
        return;
    }
    else {
        currentState = FOLLOWING;
    }

    float petPath = sqrt(deltaX * deltaX + deltaY * deltaY);
    float directionX = deltaX / petPath;
    float directionY = deltaY / petPath;
    float movementX = directionX * speed;
    float movementY = directionY * speed;
    posX += movementX * deltaTime;
    posY += movementY * deltaTime;
}

float Pet::getPosX(){
    return posX;
}
float Pet::getPosY() {
    return posY;
}
