#include "mapboard.h"
#include "mapfile.h"
#include <string>

using namespace std;

string encodeMap(PacmanBoard map) {
	string encodedMap = "";

	for (int i = 0; i < map.width(); i++) {
		for (int j = 0; j < map.height(); j++) {
			encodedMap += to_string(map.getTile(i, j));
		}
	}

	return encodedMap;
}

PacmanBoard decodeMap(string encodedMap, int width, int height) {
	PacmanBoard map(width, height);

	if (encodedMap.length() != width * height) {
		if ((encodedMap.length() == width * height + 1 && encodedMap[encodedMap.length() - 1] == '\r')
		 || (encodedMap.length() == width * height + 1 && encodedMap[encodedMap.length() - 1] == '\n')
		 || (encodedMap.length() == width * height + 2 && encodedMap[encodedMap.length() - 2] == '\r' && encodedMap[encodedMap.length() - 1] == '\n')) {
			encodedMap.erase(encodedMap.begin() + width * height, encodedMap.end());
		} else {
			return map;
		}
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			string s(1, encodedMap[i * height + j]);
			map.setTile(i, j, (Tile)stoi(s));
		}
	}

	return map;
}

bool mapGood(PacmanMapfile map) {
	return map.hasProperty("width")
	    && map.hasProperty("height")
	    && map.hasProperty("board")
	    && map.hasProperty("name");
}

PacmanBoard loadMap(PacmanMapfile map) {
	if (!mapGood(map)) {
		PacmanBoard board(0, 0);
		return board;
	}

	string encodedMap = map.getProperty("board");
	int width = map.getPropertyInt("width");
	int height = map.getPropertyInt("height");
	PacmanBoard board = decodeMap(encodedMap, width, height);
	return board;
}

PacmanBoard loadMap(string filename) {
	PacmanMapfile map(filename);
	return loadMap(map);
}

void saveMap(string filename, PacmanBoard board, string name) {
	PacmanMapfile map;
	map.setPropertyInt("width", board.width());
	map.setPropertyInt("height", board.height());
	map.setProperty("board", encodeMap(board));
	map.setProperty("name", name);
	map.save(filename);
}
