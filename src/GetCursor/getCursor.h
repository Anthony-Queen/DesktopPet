#pragma once
#include <functional>
#include <string>

void setBackend(std::string Backend, void(*&getCursorPos)(float&, float&));
