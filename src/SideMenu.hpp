#ifndef SIDE_MENU
#define SIDE_MENU

#include "libs.hpp"
#include "Renderable.hpp"

class SideMenu : public Renderable {
  public:
  SideMenu();
  void render(Renderer* renderer, bool& rerender) override;
  void update() override;
  void handleEvent(const SDL_Event& event, Window& window, bool& rerender) override;
};

#endif