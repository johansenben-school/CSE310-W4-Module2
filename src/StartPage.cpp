#include "StartPage.hpp"
#include "GamePage.hpp"

#include "Window.hpp"

void StartPage::render(Renderer* renderer, bool& rerender)
{
  //todo make start page better
  if (!rerender) //only rerender when changes are made
    return;
  renderer->renderText("Start", {255,255,255,255}, 30, 200);
  this->startBtn = renderer->textRect;
}

void StartPage::update()
{
}

void StartPage::handleEvent(const SDL_Event& event, Window& window, bool& rerender)
{
  //click event
  if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
    SDL_Point mouse = { event.button.x, event.button.y };
    if (SDL_PointInRect(&mouse, &startBtn)) {
      //if start was clicked, switch the current paage to a new game
      GamePage* page = new GamePage();
      window.changePage(page);
      rerender = true;
    }
  }
}
