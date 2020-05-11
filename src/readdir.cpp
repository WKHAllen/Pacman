#include "readdir.h"
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

bool endsWith(string const &fullString, string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

vector<string> listFiles(string path) {
	vector<string> files;

	for (const auto &entry : filesystem::directory_iterator(path)) {
		if (entry.is_regular_file()) {
			files.push_back(entry.path().string());
		}
	}

	return files;
}

vector<string> listFilesByExt(string path, string ext) {
	vector<string> files;

	for (const auto &entry : filesystem::directory_iterator(path)) {
		if (entry.is_regular_file()) {
			if (endsWith(entry.path().string(), ext)) {
				files.push_back(entry.path().string());
			}
		}
	}

	return files;
}
