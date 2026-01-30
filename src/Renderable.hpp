#ifndef RENDERABLE
#define RENDERABLE

#include "util.hpp"
#include "Renderer.hpp"

class Window;

class Renderable {
  //virtual class; use inheritance
  public:
  virtual ~Renderable() = default;
  virtual void render(Renderer* renderer, bool& rerender) = 0;
  virtual void update() = 0;
  virtual void handleEvent(const SDL_Event& event, Window& window, bool& rerender) = 0;
};



#endif