#include "Pawn.hpp"

Pawn::Pawn(PieceColor color, int x, int y): Piece(color, x, y)
{
}

void Pawn::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>>& board)
{
  int yDirection = this->color == PieceColor::WHITE ? -1 : 1;
  //1 square
  if (
    y + yDirection >= 0 && y + yDirection < 8 //if square is on the board
    && board[(this->y + yDirection) * 8 + this->x]->isEmpty() //if square is empty
  ) {
    moves[(this->y + yDirection) * 8 + this->x] = MoveTypes::VALID;
  }
  //2 sguares
  if (
    this->y + yDirection * 2 >= 0 && this->y + yDirection * 2 < 8 //if square is on the board
    && board[(this->y + yDirection) * 8 + this->x]->isEmpty() //1st square is empty
    && board[(this->y + yDirection * 2) * 8 + this->x]->isEmpty() && isFirstMove //2nd square is empty
  ) {
    moves[(this->y + yDirection * 2) * 8 + this->x] = MoveTypes::PAWN_MOVES_2_SQUARES;
  }
  //diagonal kill
  for (int xDirection = -1; xDirection <= 1; xDirection += 2) {
    if (this->x + xDirection < 0 || this->x + xDirection >= 8)//is x within bounds
      continue;
    if (this->y + yDirection < 0 || this->y + yDirection >= 8)//is y within bounds
      continue;
    int i = (this->y + yDirection) * 8 + this->x + xDirection;
    if (!board[i]->isEmpty() && board[i]->getColor() != this->color) //is target an enemy peice
      moves[i] = MoveTypes::VALID_KILL;
  }
  //pawn reaches the end
  for (int x = 0; x < 8; x++) {
    if (moves[x] == MoveTypes::VALID)
      moves[x] = MoveTypes::PAWN_TO_END;
    else if (moves[x] == MoveTypes::VALID_KILL)
      moves[x] = MoveTypes::PAWN_KILL_TO_END;
    else if (moves[56 + x] == MoveTypes::VALID)
      moves[56 + x] = MoveTypes::PAWN_TO_END;
    else if (moves[56 + x] == MoveTypes::VALID_KILL)
      moves[56 + x] = MoveTypes::PAWN_KILL_TO_END;
  }
}
