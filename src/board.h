#ifndef PACMAN_BOARD_H
#define PACMAN_BOARD_H

typedef enum _Tile {
	Space, Wall, Food
} Tile;

typedef struct _PacmanBoard {
	int width;
	int height;
	Tile **tiles;
} PacmanBoard;

PacmanBoard *create_board(int width, int height);
Tile get_tile(PacmanBoard *board, int x, int y);
void set_tile(PacmanBoard *board, int x, int y, Tile tile);
void destroy_board(PacmanBoard *board);

#endif // PACMAN_BOARD_H
