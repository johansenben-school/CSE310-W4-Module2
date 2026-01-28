#ifndef BOARD
#define BOARD

#include "libs.hpp"
#include "Renderable.hpp"
#include "vector"
#include "Piece.hpp"

class Board : public Renderable {
  std::vector<Piece> board;
  public:
  Board();
  void render(Renderer* renderer) override;
  void update() override;
  void handleEvent(const SDL_Event& event, Window& window) override;
};

#endif