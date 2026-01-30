#include "StartPage.hpp"
#include "GamePage.hpp"

#include "Window.hpp"

void StartPage::render(Renderer* renderer, bool& rerender)
{
  if (!rerender)
    return;
  renderer->renderText("start", {255,255,255,255}, 30, 200);
  this->startBtn = renderer->textRect;
}

void StartPage::update()
{
}

void StartPage::handleEvent(const SDL_Event& event, Window& window, bool& rerender)
{
  if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
    SDL_Point mouse = { event.button.x, event.button.y };
    if (SDL_PointInRect(&mouse, &startBtn)) {
      GamePage* page = new GamePage();
      window.changePage(page);
      rerender = true;
    }
  }
}
