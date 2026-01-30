#include "Knight.hpp"

Knight::Knight(PieceColor color, int x, int y): Piece(color, x, y)
{
}

void Knight::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board, int lastMoveIndex)
{
  for (int y = -2; y <= 2; y += 1) {
    for (int x = -2; x <= 2; x += 1) {
      if (std::abs((float)x / y) == 2 || std::abs((float)x / y) == 0.5) {//x-y ratio i2 a 2:1 ratio
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
}
