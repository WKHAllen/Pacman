#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "world/board.h"
#include "entity/player.h"
#include "entity/ghost.h"

typedef struct _PacmanGame {
	PacmanBoard *board;
	PacmanPlayer *player;
	PacmanGhost **ghosts;
} PacmanGame;

#endif // PACMAN_GAME_H
