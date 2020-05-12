#ifndef PACMAN_MAPFILE_H
#define PACMAN_MAPFILE_H

#include <unordered_map>
#include <string>
#include "world/tile.h"
#include "world/board.h"

using namespace std;

string encodeMap(PacmanBoard map);
PacmanBoard decodeMap(string encodedMap);

class PacmanMapfile {
	private:
		string filename;
		unordered_map<string, string> properties;

	public:
		PacmanMapfile();
		PacmanMapfile(string mapfile);
		string getProperty(string key);
		void setProperty(string key, string value);
		bool propertyExists(string key);
		bool save();
		bool save(string mapfile);
};

#endif // PACMAN_MAPFILE_H
