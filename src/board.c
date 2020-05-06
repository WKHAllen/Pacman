#include <stdlib.h>
#include "board.h"

PacmanBoard *create_board(int width, int height)
{
	PacmanBoard *board = malloc(sizeof(*board));

	board->width = width;
	board->height = height;
	
	Tile **tiles = (Tile **)malloc(width * sizeof(Tile *));
	for (int i = 0; i < width; i++)
		tiles[i] = (Tile *)malloc(height * sizeof(Tile));
	board->tiles = tiles;

	return board;
}

Tile get_tile(PacmanBoard *board, int x, int y)
{
	return board->tiles[x][y];
}

void set_tile(PacmanBoard *board, int x, int y, Tile tile)
{
	board->tiles[x][y] = tile;
}

void destroy_board(PacmanBoard *board)
{
	for (int i = 0; i < board->width; i++)
		free(board->tiles[i]);
	free(board->tiles);
	free(board);
}
