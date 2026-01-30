#ifndef START_MENU
#define START_MENU

#include "libs.hpp"
#include "Renderable.hpp"

class StartPage : public Renderable {
  SDL_Rect startBtn = { 0, 0, 0, 0 };
  public:
  void render(Renderer* renderer, bool& rerender) override;
  void update() override;
  void handleEvent(const SDL_Event& event, Window& window, bool& rerender) override;

};

#endif