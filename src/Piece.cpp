#include "Piece.hpp"

Piece::Piece(PieceType type, PieceColor color, int x, int y)
{
  this->type = type;
  this->x = x;
  this->y = y;
  this->color = color;
}

bool Piece::isEmpty()
{
  return this->type == PieceType::NONE || this->color == PieceColor::NONE;
}