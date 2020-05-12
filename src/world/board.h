#ifndef PACMAN_BOARD_H
#define PACMAN_BOARD_H

#include "tile.h"
#include <vector>

using namespace std;

class PacmanBoard {
	private:
		int w;
		int h;
		vector<vector<Tile>> board;

	public:
		PacmanBoard(int width, int height);
		int width();
		int height();
		Tile getTile(int x, int y);
		void setTile(int x, int y, Tile tile);
		void fill(Tile tile);
};

#endif // PACMAN_BOARD_H
