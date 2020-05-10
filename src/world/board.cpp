#include "board.h"
#include <vector>

using namespace std;

PacmanBoard::PacmanBoard(int width, int height) {
	w = width;
	h = height;
	board.resize(w, vector<Tile>(h));
}

Tile PacmanBoard::getTile(int x, int y) {
	return board[x][y];
}

void PacmanBoard::setTile(int x, int y, Tile tile) {
	board[x][y] = tile;
}

void PacmanBoard::fill(Tile tile) {
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			board[i][j] = tile;
}
