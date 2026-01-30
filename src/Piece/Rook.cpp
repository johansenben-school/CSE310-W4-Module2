#include "Rook.hpp"



Rook::Rook(PieceColor color, int x, int y) : Piece(color, x, y)
{
  
}

void Rook::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board)
{
  this->getMovesIn1Dir(moves, board,1,0);
  this->getMovesIn1Dir(moves, board,-1,0);
  this->getMovesIn1Dir(moves, board,0,1);
  this->getMovesIn1Dir(moves, board,0,-1);
}
