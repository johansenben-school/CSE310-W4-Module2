#include "GamePage.hpp"


GamePage::GamePage()
{
  this->board = Board();
}

void GamePage::render(Renderer *renderer)
{
  board.render(renderer);
}

void GamePage::update()
{
  board.update();
}

void GamePage::handleEvent(const SDL_Event& event, Window& window)
{
  board.handleEvent(event, window);
}
