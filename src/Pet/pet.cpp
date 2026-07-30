#include "pet.h"
#include <cmath>

void Pet::moveTo(float x, float y, float deltaTime) {
    float deltaX = x - posX;
    float deltaY = y - posY;
    float petPath = sqrt(deltaX * deltaX + deltaY * deltaY);
    float directionX = deltaX / petPath;
    float directionY = deltaY / petPath;
    float movementX = directionX * speed;
    float movementY = directionY * speed;
    posX += movementX * deltaTime;
    posY += movementY * deltaTime;
}
