#ifndef PACMAN_MAPBOARD_H
#define PACMAN_MAPBOARD_H

#include <string>
#include "world/tile.h"
#include "world/board.h"
#include "mapfile.h"

using namespace std;

string encodeMap(PacmanBoard map);
PacmanBoard decodeMap(string encodedMap, int width, int height);
PacmanBoard loadMap(PacmanMapfile map);
PacmanBoard loadMap(string filename);
void saveMap(string filename, PacmanBoard board, string name);

#endif // PACMAN_MAPBOARD_H
