#pragma once
#include <string>

class Pet {
    public:
        void moveTo(float x, float y, float deltaTime);
    private:
        float speed = 10;
        float posX;
        float posY;
        std::string name;
};
