#include <stdio.h>

int main(int argc, char **argv)
{
	
	FILE *board;

	char board_name[] = "../board/";
	
	strcat(board_name, argv[1]);

	puts(board_name);

	return 0;

}
