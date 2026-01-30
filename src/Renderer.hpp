#ifndef RENDERER
#define RENDERER

#include "util.hpp"

class Renderer {
  SDL_Renderer* renderer;

  TTF_Font* font;
  SDL_Surface* textSurface;
  SDL_Texture* textTexture;
  std::string lastText;
  public:
  SDL_Rect textRect = { 0, 0, 0, 0 };

  //constructor/destructor
  Renderer(SDL_Renderer* r);
  ~Renderer();

  //methods
  void setColor(SDL_Color color);
  void renderText(std::string text, SDL_Color color, int x, int y, bool rerender = false);
  void renderRect(int x, int y, int width, int height);
  void renderPolygon(int points, int x, int y, int radius);
  void renderClear(bool rerender);
  void renderPresent();
};

#endif