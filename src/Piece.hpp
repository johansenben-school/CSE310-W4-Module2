#ifndef PIECE
#define PIECE

enum class PieceType : int {
  PAWN = 0, ROOK = 1, KNIGHT = 2, BISHOP = 3, KING = 4, QUEEN = 5, NONE = 6
};
enum class PieceColor : int {
  BLACK = 0, WHITE = 1, NONE = 2
};
class Piece {
  
  public:
  PieceType type;
  PieceColor color;
  int x, y;
  Piece() : type(PieceType::NONE), color(PieceColor::NONE), x(-1), y(-1) {}
  Piece(PieceType type, PieceColor color, int x, int y);
  bool isEmpty();
};

#endif