#include "Bishop.hpp"

Bishop::Bishop(PieceColor color, int x, int y): Piece(color, x, y)
{
}

void Bishop::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board, int lastMoveIndex)
{
  this->getMovesIn1Dir(moves, board, 1, 1); //down-right
  this->getMovesIn1Dir(moves, board, -1, 1); //down-left
  this->getMovesIn1Dir(moves, board, 1, -1); //up-right
  this->getMovesIn1Dir(moves, board, -1, -1); //up-left
}
