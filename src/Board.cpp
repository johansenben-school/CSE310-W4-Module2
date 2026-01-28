#include "Board.hpp"

Board::Board()
{
  this->board = std::vector<Piece>();
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      PieceType type = PieceType::NONE;
      PieceColor color = PieceColor::NONE;
      if (y < 2 || y >= 6) {
        color = y < 2 ? PieceColor::BLACK : PieceColor::WHITE;
        if (y == 1 || y == 6)
          type = PieceType::PAWN;
        else if (x == 0 || x == 7)
          type = PieceType::ROOK;
        else if (x == 1 || x == 6)
          type = PieceType::KNIGHT;
        else if (x == 2 || x == 5)
          type = PieceType::BISHOP;
        else if (x == 3)
          type = PieceType::KING;
        else
          type = PieceType::QUEEN;
      }
      this->board.emplace_back(Piece(type, color, x, y));
      std::cout <<y*8+x<<" " << std::to_string(static_cast<int>(type)) << " " << static_cast<int>(color) << "\n";
    }
  }
}

void Board::render(Renderer *renderer)
{
  renderer->setColor(SQUARE_WHITE);
  for (int color = 0; color <= 1; color++) {
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if ((x + y) % 2 == color)
          renderer->renderRect(x * SQUARE_WIDTH, y * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH);
      }
    }
    renderer->setColor(SQUARE_BLACK);
  }
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int i = y * 8 + x;
      if (!this->board[i].isEmpty()) {
        std::cout << i << " " << (this->board[i].color == PieceColor::BLACK ? "black" : "white") << "\n";
        renderer->renderText(std::to_string(static_cast<int>(this->board[i].type)), this->board[i].color == PieceColor::BLACK ? PIECE_BLACK : PIECE_WHITE, x * SQUARE_WIDTH, y * SQUARE_WIDTH, true);
      }
    }
  }
}

void Board::update()
{
}

void Board::handleEvent(const SDL_Event& event, Window& window)
{
}
