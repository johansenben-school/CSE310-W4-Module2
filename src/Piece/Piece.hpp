#ifndef PIECE
#define PIECE

#include "../util.hpp"

//util enums
enum class PieceType : int {
  PAWN = 0, ROOK = 1, KNIGHT = 2, BISHOP = 3, KING = 4, QUEEN = 5, NONE = 6
};
enum class PieceColor : int {
  BLACK = 0, WHITE = 1, NONE = 2
};
enum class MoveTypes: int {
  INVALID = 0, VALID = 1, VALID_CASTLE = 2, VALID_EN_PASSANT = 3, PAWN_TO_END = 4, PAWN_MOVES_2_SQUARES = 5, VALID_KILL = 6, PAWN_KILL_TO_END = 7
};


class Piece {
  //virtual class; empty piece by default, each piece type is a derived class
  protected:
  PieceColor color;
  int x, y;
  bool isFirstMove = true;
  MoveTypes lastMove = MoveTypes::INVALID;

  //private method
  void getMovesIn1Dir(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board, int xMultiplier, int yMultiplier);

  public:
  //constructrs/destructor
  Piece() : color(PieceColor::NONE), x(-1), y(-1) {}
  Piece(PieceColor color, int x, int y);
  virtual ~Piece() = default;

  //getters/setters
  PieceColor getColor() { return this->color; }
  void setIsFirstMove(bool isFirstMove) { this->isFirstMove = isFirstMove; }
  void setCoord(int index) { this->x = index % 8; this->y = index / 8; }
  MoveTypes getLastMove() { return this->lastMove; }
  
  //methods
  virtual bool isEmpty() { return true; }; //base Piece class is always empty and shouldnt be used as an actual piece
  virtual PieceType getType() { return PieceType::NONE; }
  virtual bool canSelect(PieceColor turnColor);
  virtual void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board, int lastMoveIndex);
  virtual void postMove(MoveTypes lastMove, std::vector<std::unique_ptr<Piece>>& board, int newIndex) { setCoord(newIndex); this->lastMove = lastMove; }
  virtual char getChar() { return ' '; }
};

#endif