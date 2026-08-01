#pragma once
#include <string>

class Pet {
    public:
        void moveTo(float x, float y, float deltaTime);
        enum States{FOLLOWING, IDLE, SLEEPING, PLAYING};
        States currentState = IDLE;
        float getPosX();
        float getPosY();
    private:
        float speed = 5;
        float posX;
        float posY;
        std::string name;
};
