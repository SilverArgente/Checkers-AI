#include <stdio.h>
#include <string.h>
#include "board.h"

int main(int argc, char **argv)
{
	
	FILE *board_file;
	char board_name[30] = "../board/";	
	char board_copy[8][8]; 
	char line[10];

	Board board;
	
	strcat(board_name, argv[1]);
	board_file = fopen(board_name, "r");
	
	if (board_file == NULL)
	{
		printf("Failed to open file: %s\n", argv[1]);
		return 1;
	}
	
	for (int i = 0; i < 8; i++)
	{
		
		if ( fgets(line, sizeof(line), board_file) != NULL )
		{
			for (int j = 0; j < 8; j++)
			{
				board_copy[i][j] = line[j];
			}
		}
		else
		{
			printf("Failed to read line from file\n");
			return 1;
		}

	}
	
	board = createBoard();
	setBoard(&board, board_copy);
	setMovingSide(&board, argv[2][0]); 
	
	

	return 0;

}
