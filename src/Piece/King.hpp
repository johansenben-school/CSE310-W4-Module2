#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public Piece {
  public:
  King() = default;
  King(PieceColor color, int x, int y);

  PieceType getType() override { return PieceType::KING; }
  bool isEmpty() override {return this->color == PieceColor::NONE || this->x == -1 || this-> y == -1; };
  void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board) override;
  char getChar() override { return 'K'; }
};

#endif