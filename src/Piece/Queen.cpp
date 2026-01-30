#include "Queen.hpp"

Queen::Queen(PieceColor color, int x, int y): Piece(color, x, y)
{
}

void Queen::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board, int lastMoveIndex)
{
  //horizontal
  this->getMovesIn1Dir(moves, board,1,0); //right
  this->getMovesIn1Dir(moves, board,-1,0); //left
  this->getMovesIn1Dir(moves, board,0,1); //down
  this->getMovesIn1Dir(moves, board,0,-1); //up

  //diagonal
  this->getMovesIn1Dir(moves, board, 1, 1); //down-right
  this->getMovesIn1Dir(moves, board, -1, 1); //down-left
  this->getMovesIn1Dir(moves, board, 1, -1); //up-right
  this->getMovesIn1Dir(moves, board, -1, -1); //up-left
}
