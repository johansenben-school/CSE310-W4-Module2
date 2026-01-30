#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public Piece {
  public:
  //constructors
  Rook() = default;
  Rook(PieceColor color, int x, int y);

  //methods
  PieceType getType() override { return PieceType::ROOK; }
  bool isEmpty() override {return this->color == PieceColor::NONE || this->x == -1 || this-> y == -1; };
  void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board, int lastMoveIndex) override;
  char getChar() override { return 'r'; }
};

#endif