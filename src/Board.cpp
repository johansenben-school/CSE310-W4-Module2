#include "Board.hpp"

void Board::selectSquare(int index)
{
  this->unselectSquare();
  this->selected = index;
  this->board[index]->getPossibleMoves(this->possibleMoves, this->board);
}

void Board::unselectSquare()
{
  this->selected = -1;
  for (int i = 0; i < 64; i ++)
    this->possibleMoves[i] = MoveTypes::INVALID;
}

void Board::move(int toIndex)
{
  this->board[selected]->setIsFirstMove(false);
  std::swap(this->board[toIndex], this->board[selected]);
  this->board[selected] = std::make_unique<Piece>(Piece(PieceColor::NONE, -1, -1));
  this->board[toIndex]->setCoord(toIndex);
}

void Board::switchTurn()
{
  this->turnColor = this->turnColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;

}

Board::Board()
{
  this->board = std::vector<std::unique_ptr<Piece>>();
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      PieceColor color = PieceColor::NONE;
      if (y < 2 || y >= 6) {
        color = y < 2 ? PieceColor::BLACK : PieceColor::WHITE;
        if (y == 1 || y == 6)
          this->board.emplace_back(std::make_unique<Pawn>(Pawn(color, x, y)));
        else if (x == 0 || x == 7)
          this->board.emplace_back(std::make_unique<Rook>(Rook(color, x, y)));
        else if (x == 1 || x == 6)
          this->board.emplace_back(std::make_unique<Knight>(Knight(color, x, y)));
        else if (x == 2 || x == 5)
          this->board.emplace_back(std::make_unique<Bishop>(Bishop(color, x, y)));
        else if (x == 3)
          this->board.emplace_back(std::make_unique<King>(King(color, x, y)));
        else
          this->board.emplace_back(std::make_unique<Queen>(Queen(color, x, y)));
      } else {
        this->board.emplace_back(std::make_unique<Piece>(Piece(PieceColor::NONE, -1, -1)));
      }
    }
  }
}

void Board::render(Renderer *renderer, bool& rerender)
{
  //squares
  renderer->setColor(SQUARE_WHITE);
  for (int color = 0; color <= 1; color++) {
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if (y * 8 + x == this->selected) {
          renderer->setColor(SQUARE_SELECTED);
          renderer->renderRect(x * SQUARE_WIDTH, y * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH);
          renderer->setColor(color == 0 ? SQUARE_WHITE : SQUARE_BLACK);
        } else if ((x + y) % 2 == color) {
          renderer->renderRect(x * SQUARE_WIDTH, y * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH);
        }
      }
    }
    renderer->setColor(SQUARE_BLACK);
  }
  //pieces
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int i = y * 8 + x;
      if (!this->board[i]->isEmpty()) {
        renderer->renderText(std::string(1, this->board[i]->getChar()), this->board[i]->getColor() == PieceColor::BLACK ? PIECE_BLACK : PIECE_WHITE, x * SQUARE_WIDTH, y * SQUARE_WIDTH, true);
      }
    }
  }
  //hints
  renderer->setColor(HINT_VALID);
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (possibleMoves[y * 8 + x] != MoveTypes::INVALID) {
        renderer->renderPolygon(8, x * SQUARE_WIDTH + SQUARE_WIDTH / 2, y * SQUARE_WIDTH + SQUARE_WIDTH / 2, SQUARE_WIDTH / 4);
      }
    }
  }
}

void Board::update()
{
}

void Board::handleEvent(const SDL_Event& event, Window& window, bool& rerender)
{
  if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
    int x = event.button.x / SQUARE_WIDTH;
    int y = event.button.y / SQUARE_WIDTH;
    if (x >= 8 || y >= 8)
      return;
    int i = y * 8 + x;
    if (this->selected != -1 && this->possibleMoves[i] != MoveTypes::INVALID) {
      this->move(i);
      this->unselectSquare();
      this->switchTurn();
    } else if (i == this->selected || !this->board[i]->canSelect(this->turnColor)) {
      this->unselectSquare();
    } else {
      this->selectSquare(i);
    }
    rerender = true;
  }
}
