#ifndef PIECE
#define PIECE

#include "../libs.hpp"

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
  protected:
  PieceColor color;
  int x, y;
  bool isFirstMove = true;
  void getMovesIn1Dir(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board, int xMultiplier, int yMultiplier);

  public:
  Piece() : color(PieceColor::NONE), x(-1), y(-1) {}
  Piece(PieceColor color, int x, int y);
  virtual ~Piece() = default;

  PieceColor getColor() { return this->color; }
  void setIsFirstMove(bool isFirstMove) { this->isFirstMove = isFirstMove; }
  void setCoord(int index) { this->x = index % 8; this->y = index / 8; }
  
  virtual bool isEmpty() { return true; }; //base Piece class is always empty and shouldnt be used as an actual piece
  virtual PieceType getType() { return PieceType::NONE; }
  virtual bool canSelect(PieceColor turnColor);
  virtual void getPossibleMoves(std::array<MoveTypes, 64>& moves, std::vector<std::unique_ptr<Piece>>& board);
  virtual char getChar() { return ' '; }
};

#endif