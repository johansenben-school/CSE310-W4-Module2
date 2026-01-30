#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece {
  public:
  Knight() = default;
  Knight(PieceColor color, int x, int y);

  PieceType getType() override { return PieceType::KNIGHT; }
  bool isEmpty() override {return this->color == PieceColor::NONE || this->x == -1 || this-> y == -1; };
  void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board) override;
  char getChar() override { return 'k'; }
};

#endif