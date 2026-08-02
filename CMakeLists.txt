cmake_minimum_required(VERSION 3.20)

project(DesktopPet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL3 REQUIRED)


add_executable(Pet
    src/main.cpp
    src/Pet/pet.cpp
)


target_link_libraries(Pet
    SDL3::SDL3
)
