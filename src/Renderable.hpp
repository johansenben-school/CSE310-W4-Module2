#ifndef RENDERABLE
#define RENDERABLE

#include "libs.hpp"
#include "Renderer.hpp"

class Window;

class Renderable {
  public:
  virtual ~Renderable() = default;
  virtual void render(Renderer* renderer, bool& rerender) = 0;
  virtual void update() = 0;
  virtual void handleEvent(const SDL_Event& event, Window& window, bool& rerender) = 0;
};



#endif