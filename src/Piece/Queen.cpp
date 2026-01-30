#include "Queen.hpp"

Queen::Queen(PieceColor color, int x, int y): Piece(color, x, y)
{
}

void Queen::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board)
{
  //horizontal
  this->getMovesIn1Dir(moves, board,1,0);
  this->getMovesIn1Dir(moves, board,-1,0);
  this->getMovesIn1Dir(moves, board,0,1);
  this->getMovesIn1Dir(moves, board,0,-1);

  //diagonal
  this->getMovesIn1Dir(moves, board, 1, 1);
  this->getMovesIn1Dir(moves, board, -1, 1);
  this->getMovesIn1Dir(moves, board, 1, -1);
  this->getMovesIn1Dir(moves, board, -1, -1);
}
