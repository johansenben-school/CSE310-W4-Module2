#ifndef Queen_HPP
#define Queen_HPP

#include "Piece.hpp"

class Queen : public Piece {
  public:
  //constructos
  Queen() = default;
  Queen(PieceColor color, int x, int y);

  //methods
  PieceType getType() override { return PieceType::QUEEN; }
  bool isEmpty() override {return this->color == PieceColor::NONE || this->x == -1 || this-> y == -1; };
  void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board, int lastMoveIndex) override;
  char getChar() override { return 'q'; }
};

#endif