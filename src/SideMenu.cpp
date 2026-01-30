#include "SideMenu.hpp"

SideMenu::SideMenu()
{
}

void SideMenu::render(Renderer *renderer, bool& rerender)
{
  //todo - actually render things
  if (!rerender)
    return;
}

void SideMenu::update()
{
}

void SideMenu::handleEvent(const SDL_Event& event, Window& window, bool& rerender)
{
}
