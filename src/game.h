#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "board.h"
#include "player.h"
#include "ghost.h"

typedef struct _PacmanGame {
	PacmanBoard *board;
	PacmanPlayer *player;
	PacmanGhost **ghosts;
} PacmanGame;

#endif // PACMAN_GAME_H
