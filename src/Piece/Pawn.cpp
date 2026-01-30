#include "Pawn.hpp"

Pawn::Pawn(PieceColor color, int x, int y): Piece(color, x, y)
{
}

void Pawn::getPossibleMoves(std::array<MoveTypes, 64> &moves, std::vector<std::unique_ptr<Piece>>& board, int lastMoveIndex)
{
  int yDirection = this->color == PieceColor::WHITE ? -1 : 1;
  //1 square, no kill
  if (
    y + yDirection >= 0 && y + yDirection < 8 //if square is on the board
    && board[(this->y + yDirection) * 8 + this->x]->isEmpty() //if square is empty
  ) {
    moves[(this->y + yDirection) * 8 + this->x] = MoveTypes::VALID;
  }
  //2 sguares, no kill
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
  //check if pawn reaches the end
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
  //en passant (if a pawn moves 2 squares on it's first turn, an enemy pawn can kill it like it only moved 1 square)
  if (lastMoveIndex != -1 && (this->y == 3 && this->color == PieceColor::WHITE) || (this->y == 4 && this->color == PieceColor::BLACK)) {
    for (int xOffset = - 1; xOffset <= 1; xOffset += 2) {
      int neighborIndex = this->y * 8 + this->x + xOffset;
      if (!board[neighborIndex]->isEmpty() && board[neighborIndex]->getColor() != this->color && board[neighborIndex]->getLastMove() == MoveTypes::PAWN_MOVES_2_SQUARES) {
        moves[(this->y + yDirection) * 8 + this->x + xOffset] = MoveTypes::VALID_EN_PASSANT;
      }
    }
  }
}

void Pawn::postMove(MoveTypes lastMove, std::vector<std::unique_ptr<Piece>> &board, int newIndex)
{
  Piece::postMove(lastMove, board, newIndex);
  
  //handle en passant
  switch (lastMove) {
    case MoveTypes::VALID_EN_PASSANT: 
    {
      int yDirection = this->color == PieceColor::WHITE ? -1 : 1;
      board[(this->y - yDirection) * 8 + x] = std::make_unique<Piece>(Piece(PieceColor::NONE, -1, -1));
      break;
    }
    default: 
      break;
  }
}
