#ifndef BOARD_H
#define BOARD_H
// Define a Checkers board class and needed member functions
/* List of character meanings
   o - open tile
   b - black piece
   r - red piece
   a - kinged black piece
   t - kinged red piece
*/

typedef struct Board
{
	char **board;
	char moving_side;

} Board;

Board createBoard();
void setBoard(Board *board, char copy[8][8]);
void setMovingSide(Board *board, char side);
void freeBoard(Board *board);

#endif
