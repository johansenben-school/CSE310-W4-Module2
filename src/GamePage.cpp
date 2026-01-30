#include "GamePage.hpp"


GamePage::GamePage()
{
  this->board = Board();
}

void GamePage::render(Renderer *renderer, bool& rerender)
{
  if (!rerender)
    return;
  board.render(renderer, rerender);
  //render side menu
}

void GamePage::update()
{
  board.update();
}

void GamePage::handleEvent(const SDL_Event& event, Window& window, bool& rerender)
{
  board.handleEvent(event, window, rerender);
}
