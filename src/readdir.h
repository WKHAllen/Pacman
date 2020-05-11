#ifndef PACMAN_READDIR_H
#define PACMAN_READDIR_H

#include <string>
#include <vector>

using namespace std;

vector<string> listFiles(string path);
vector<string> listFilesByExt(string path, string ext);

#endif // PACMAN_READDIR_H
