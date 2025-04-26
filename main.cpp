#include "core.h"
#include "board.h"
#include "piece.h"
#include "list.h"
#include <iostream>
#include <SDL3/SDL.h>

#define WINDOW_W 518
#define WINDOW_H 720
SDL_Window* window;
SDL_Renderer *renderer;
SDL_Surface *background;
SDL_Texture *texture;
Board* board;
int result;

int init() {
    if (board == nullptr) {
        result = 0;
        board = new Board();
        window = SDL_CreateWindow("Tetris", WINDOW_W, WINDOW_H, SDL_WINDOW_OPENGL);
        if (!window) {
            SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
            SDL_Quit();
            return 1;
        }
        renderer = SDL_CreateRenderer(window, NULL);
        if(renderer == NULL)
            SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), window);
        background = SDL_LoadBMP("/Users/ljubomir/Developer/Tetris/assets/background.bmp");
        if(background == NULL)
            SDL_ShowSimpleMessageBox(0, "Background init error", SDL_GetError(), window);
        texture = SDL_CreateTextureFromSurface(renderer,background);
        if(texture == NULL)
            SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(), window);
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    } else {}

    if (board == nullptr)
        return 0;
    return 1;
}

int onClose() {
    if (board != nullptr) {
        delete board;
        board = nullptr;
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    }
    
    return 1;
}

int main() {
    if (init()) {
        SDL_Event e;
        bool running = true;

        while (running) {
            SDL_Delay(1000);
            while (SDL_PollEvent(&e)) {
                switch(e.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    SDL_DestroyTexture(texture);
                    SDL_DestroySurface(background);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (e.key.scancode == SDL_SCANCODE_LEFT) {
                        // Handle left arrow key
                    }
                    break;
                }
            }
        }
    }

    return onClose();
}

