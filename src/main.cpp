#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "game.h"
#include "readdir.h"
#include "mapfile.h"

using namespace std;

const string mapDirPath = "map";

void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

bool getInt(int *result) {
	int retCode = scanf("%d", result);

	if (retCode == EOF)
		return false;
	if (retCode == 0) {
		while (fgetc(stdin) != '\n') {}
		return false;
	}

	return true;
}

int selection(string prompt, int numOptions, string options[]) {
	cout << prompt << endl << endl;
	for (int i = 0; i < numOptions; i++) {
		cout << setfill(' ') << setw(4) << i + 1;
		cout << ". " << options[i] << endl;
	}

	cout << endl << "> ";
	int choice = 0;
	int retCode = getInt(&choice);
	while (!retCode || choice < 1 || choice > numOptions) {
		cout << "Please enter an integer between 1 and " << numOptions << "." << endl << "> ";
		retCode = getInt(&choice);
	}

	return choice;
}

string selectMap(string mapDir) {
	vector<string> files = listFilesByExt(mapDir, ".pacmap");
	if (files.size() == 0)
		return "";
	int numFiles = files.size();

	cout << "Select a map:" << endl << endl;
	for (int i = 0; i < numFiles; i++) {
		cout << setfill(' ') << setw(4) << i + 1;
		cout << ". " << files[i] << endl;
	}

	cout << endl << "> ";
	int choice = 0;
	int retCode = getInt(&choice);
	while (!retCode || choice < 1 || choice > numFiles) {
		cout << "Please enter an integer between 1 and " << numFiles << "." << endl << "> ";
		retCode = getInt(&choice);
	}

	return files[choice - 1];
}

void play(string mapFile) {
	// TODO: start game
}

void pause(string prompt) {
	int ch;
	do
		ch = fgetc(stdin);
	while (ch != EOF && ch != '\n');
	clearerr(stdin);
	cout << prompt;
	fflush(stdout);
	getchar();
}

int main(int argc, char *argv[]) {
	bool done = false;
	do {
		clearScreen();
		cout << "        P A C M A N        " << endl << endl;

		string options[] = {"Play the game", "Make/edit a map", "Quit"};
		int selected = selection("Welcome to Pacman! What would you like to do?", sizeof(options) / sizeof(options[0]), options);
		clearScreen();

		string mapFile;
		switch (selected) {
			case 1: ;
				mapFile = selectMap(mapDirPath);
				if (mapFile.length() == 0)
					pause("No map files found. Press enter to return to the menu.");
				else
					play(mapFile);
				break;
			case 2:
				// TODO: launch map editor
				break;
			case 3:
				done = true;
				break;
		}
	} while (!done);

	clearScreen();
	cout << "Thanks for playing!" << endl;
	return 0;
}
