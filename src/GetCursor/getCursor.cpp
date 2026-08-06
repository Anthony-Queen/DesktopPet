#include "getCursor.h"
#include <SDL3/SDL_mouse.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string>


//Hyprland Stuff Hyprrrrr Hyprrrrr
void getCursorHyprland(float& x, float& y)
{
    const char* runtime = std::getenv("XDG_RUNTIME_DIR");
    const char* signature = std::getenv("HYPRLAND_INSTANCE_SIGNATURE");

    if (!runtime || !signature)
        return;

    std::string path =
        std::string(runtime) +
        "/hypr/" +
        signature +
        "/.socket.sock";

    int sock = socket(AF_UNIX, SOCK_STREAM, 0);

    if(sock == -1)
        return;

    sockaddr_un address{};
    address.sun_family = AF_UNIX;

    std::strncpy(
        address.sun_path,
        path.c_str(),
        sizeof(address.sun_path) - 1
    );

    if(connect(sock, (sockaddr*)&address, sizeof(address)) == -1)
    {
        close(sock);
        return;
    }

    std::string command = "/cursorpos";

    ssize_t sent = send(sock, command.c_str(), command.size(), 0);
    if(sent == -1){
        close(sock);
        return;
    }

    char buffer[128]{};

    ssize_t size = recv(sock, buffer, sizeof(buffer)-1, 0);

    close(sock);

    if(size <= 0)
        return;

    std::sscanf(buffer, "%f , %f", &x, &y);
}


void getCursorX11(float &x, float &y){
    SDL_GetGlobalMouseState(&x, &y);
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
        getCursorPos = getCursorHyprland;
    }
    else if(Backend=="cocoa"){
        //MacOS code
    }
    else if(Backend=="windows"){
        //Windows code
    }
}
