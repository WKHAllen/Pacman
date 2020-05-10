#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "world/board.h"
#include "entity/player.h"
#include "entity/ghost.h"
#include <vector>

using namespace std;

class PacmanGame {
	private:
		PacmanBoard board;
		PacmanPlayer player;
		vector<PacmanGhost> ghosts;
};

#endif // PACMAN_GAME_H
