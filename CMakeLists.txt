cmake_minimum_required(VERSION 3.20)

project(DesktopPet)

find_package(SDL3 REQUIRED)

add_executable(Pet
	src/main.cpp
	src/Pet/pet.cpp
)

target_include_directories(Pet PRIVATE src/Pet)
target_link_libraries(Pet PRIVATE SDL3::SDL3)
