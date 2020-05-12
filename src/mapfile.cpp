#include "mapfile.h"
#include "world/tile.h"
#include "world/board.h"
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string propertyDelim = "=";

vector<string> splitString(string str, string delimiter) {
	vector<string> split;
	size_t pos = 0;
	string token;

	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
		split.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	split.push_back(str);

	return split;
}

PacmanMapfile::PacmanMapfile() {
	filename = "";
}

PacmanMapfile::PacmanMapfile(string mapfile) {
	filename = mapfile;
	string line;
	ifstream infile(mapfile);

	if (infile.is_open()) {
		while (getline(infile, line)) {
			vector<string> splitLine = splitString(line, propertyDelim);
			if (splitLine.size() >= 2) {
				setProperty(splitLine[0], splitLine[1]);
			}
		}
		infile.close();
	}
}

string PacmanMapfile::getProperty(string key) {
	return properties[key];
}

int PacmanMapfile::getPropertyInt(string key) {
	return stoi(getProperty(key));
}

void PacmanMapfile::setProperty(string key, string value) {
	properties[key] = value;
}

void PacmanMapfile::setPropertyInt(string key, int value) {
	setProperty(key, to_string(value));
}

bool PacmanMapfile::hasProperty(string key) {
	return properties.find(key) != properties.end();
}

bool PacmanMapfile::save() {
	if (filename != "") {
		return save(filename);
	} else {
		return false;
	}
}

bool PacmanMapfile::save(string mapfile) {
	ofstream outfile(mapfile);

	if (outfile.is_open()) {
		for (auto property : properties) {
			outfile << property.first << propertyDelim << property.second << endl;
		}
		outfile.close();

		return true;
	} else {
		return false;
	}
}
