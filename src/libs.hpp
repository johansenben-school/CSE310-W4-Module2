#ifndef LIBS
#define LIBS

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <iostream>

#define SQUARE_WIDTH 100
#define BOARD_WIDTH (SQUARE_WIDTH * 8)

#define SIDE_MENU_WIDTH 200
#define WIN_WIDTH (BOARD_WIDTH + SIDE_MENU_WIDTH)
#define WIN_HEIGHT BOARD_WIDTH

const SDL_Color SQUARE_WHITE = SDL_Color{200, 150, 90, 255};
const SDL_Color SQUARE_BLACK = SDL_Color{90, 60, 40, 255};
const SDL_Color PIECE_BLACK = SDL_Color{0, 0, 0, 255};
const SDL_Color PIECE_WHITE = SDL_Color{255, 255, 255, 255};

#define DEBUG

#ifdef DEBUG
  #define SDL_LogError_Debug(errorType) std::cerr << errorType << "Error : " << SDL_GetError() << '\n';
#else
  #define SDL_LogError_Debug(errorType)
#endif

#endif