#ifndef LIBS
#define LIBS

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <iostream>
#include <array>

#define SQUARE_WIDTH 100
#define BOARD_WIDTH (SQUARE_WIDTH * 8)

#define SIDE_MENU_WIDTH 200
#define WIN_WIDTH (BOARD_WIDTH + SIDE_MENU_WIDTH)
#define WIN_HEIGHT BOARD_WIDTH

const SDL_Color SQUARE_WHITE = SDL_Color{200, 150, 90, 255};
const SDL_Color SQUARE_BLACK = SDL_Color{90, 60, 40, 255};
const SDL_Color SQUARE_SELECTED = SDL_Color{100, 150, 255, 255};
const SDL_Color PIECE_BLACK = SDL_Color{0, 0, 0, 255};
const SDL_Color PIECE_WHITE = SDL_Color{255, 255, 255, 255};
const SDL_Color HINT_VALID = SDL_Color{150, 150, 255, 255};

template<typename... Args>
void LOG(Args&&... args) {
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}

#define DEBUG

#ifdef DEBUG
  #define DISPLAY 1 //second monitor
  #define SDL_LogError_Debug(errorType) std::cerr << errorType << "Error : " << SDL_GetError() << '\n';
#else
  #define DISPLAY 0 //main monitor
  #define SDL_LogError_Debug(errorType)
#endif

#endif