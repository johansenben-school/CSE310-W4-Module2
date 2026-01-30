#ifndef RENDERER
#define RENDERER

#include "libs.hpp"

class Renderer {
  private:
  public:
  SDL_Renderer* renderer;

  SDL_Rect textRect = { 0, 0, 0, 0 };
  TTF_Font* font;
  SDL_Surface* textSurface;
  SDL_Texture* textTexture;
  std::string lastText;

  Renderer(SDL_Renderer* r);
  ~Renderer();
  void setColor(SDL_Color color);
  void renderText(std::string text, SDL_Color color, int x, int y, bool rerender = false);
  void renderRect(int x, int y, int width, int height);
  void renderPolygon(int points, int x, int y, int radius);
  void renderClear(bool rerender);
  void renderPresent();
};

#endif