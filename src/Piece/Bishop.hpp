#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece {
  public:
  Bishop() = default;
  Bishop(PieceColor color, int x, int y);

  PieceType getType() override { return PieceType::BISHOP; }
  bool isEmpty() override {return this->color == PieceColor::NONE || this->x == -1 || this-> y == -1; };
  void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board) override;
  char getChar() override { return 'b'; }
};

#endif