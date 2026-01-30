#include "Rook.hpp"



Rook::Rook(PieceColor color, int x, int y) : Piece(color, x, y)
{
  
}

void Rook::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>> &board, int lastMoveIndex)
{
  this->getMovesIn1Dir(moves, board,1,0); //right
  this->getMovesIn1Dir(moves, board,-1,0); //left
  this->getMovesIn1Dir(moves, board,0,1); //down
  this->getMovesIn1Dir(moves, board,0,-1); //up
}
