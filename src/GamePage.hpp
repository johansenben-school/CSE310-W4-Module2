#ifndef GAME_PAGE
#define GAME_PAGE

#include "libs.hpp"
#include "Renderable.hpp"
#include "Board.hpp"

class GamePage : public Renderable {
  Board board;
  public:
  GamePage();
  void render(Renderer* renderer) override;
  void update() override;
  void handleEvent(const SDL_Event& event, Window& window) override;
};

#endif