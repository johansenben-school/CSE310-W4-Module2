#ifndef BOARD
#define BOARD

#include "libs.hpp"
#include "Renderable.hpp"
#include "vector"
#include "Piece/Pieces.hpp"


class Board : public Renderable {
  std::vector<std::unique_ptr<Piece>> board;
  std::array<MoveTypes, 64> possibleMoves = {};
  int selected = -1;
  PieceColor turnColor = PieceColor::WHITE;
  void selectSquare(int index);
  void unselectSquare();
  void move(int toIndex);
  void switchTurn();
  public:
  Board();
  void render(Renderer* renderer, bool& rerender) override;
  void update() override;
  void handleEvent(const SDL_Event& event, Window& window, bool& rerender) override;
};

#endif