#include "Piece.hpp"

Piece::Piece(PieceColor color, int x, int y)
{
  this->x = x;
  this->y = y;
  this->color = color;
}
bool Piece::canSelect(PieceColor turnColor)
{
  return this->color == turnColor;
}

void Piece::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>>& board, int lastMoveIndex)
{
  for (int i = 0; i < 64; i++) {
    moves[i] = MoveTypes::INVALID;
  }
}

//util method; updates possible moves in 1 direction until it reaches an enemy piece or edge of board; used for queen, rook and bishop
void Piece::getMovesIn1Dir(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board, int xMultiplier, int yMultiplier)
{ 
  for (int delta = 1; delta < 8; delta++) {
    int newX = this->x + delta * xMultiplier, newY = this->y + delta * yMultiplier;
    if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8)
      return;
      int i = newY * 8 + newX;
    if (board[i]->getColor() == this->color)
      return;
    if (board[i]->isEmpty()) {
      moves[i] = MoveTypes::VALID;
      continue;
    }
    moves[i] = MoveTypes::VALID_KILL;
    return;
  }
}