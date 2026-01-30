#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece {
  public:
  //constructors
  Pawn() = default;
  Pawn(PieceColor color, int x, int y);

  //methods
  PieceType getType() override { return PieceType::PAWN; }
  bool isEmpty() override {return this->color == PieceColor::NONE || this->x == -1 || this-> y == -1; };
  void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board, int lastMoveIndex) override;
  void postMove(MoveTypes lastMove, std::vector<std::unique_ptr<Piece>>& board, int newIndex) override;
  char getChar() override { return 'p'; }
};

#endif