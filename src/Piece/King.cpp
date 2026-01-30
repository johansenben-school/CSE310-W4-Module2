#include "King.hpp"

King::King(PieceColor color, int x, int y): Piece(color, x, y)
{
}

void King::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board)
{
  for (int y = -1; y <= 1; y += 1) {
    for (int x = -1; x <= 1; x += 1) {
      //check bounds
      if (this->x + x < 0 || this->x + x >= 8 || this->y + y < 0 || this->y + y >= 8)
        continue;
      int i = (this->y + y) * 8 + this->x + x;
      //move
      if (board[i]->isEmpty()) {
        moves[i] = MoveTypes::VALID;
        continue;
      }
      //kill
      if (board[i]->getColor() != this->color) {
        moves[i] = MoveTypes::VALID_KILL;
      }
    }
  }
}
