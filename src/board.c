#include <stdlib.h>
#include <string.h>
#include "board.h"

Board createBoard()
{

	Board board;
	
	board.moving_side = 'b';
	board.board = malloc(8 * sizeof(char*));
	
	for (int i = 0; i < 8; i++)
	{	
		board.board[i] = malloc(8 * sizeof(char));
	}

	return board;	

}

void setBoard(Board *board, char copy[8][8])
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board->board[i][j] = copy[i][j];
		}
	}

}

void setMovingSide(Board *board, char side)
{
	board->moving_side = side;
}

