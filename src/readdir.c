#include "readdir.h"
#include "../bin/include/list.h"
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
	#include <windows.h>
#else
	#include <dirent.h>
#endif

List *list_files(char *path)
{
	List *files = list_new();
	char sPath[2048];

#ifdef _WIN32
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;

	sprintf(sPath, "%s\\*.*", path);

	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
		return NULL;

	do
	{
		if (strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0)
		{
			sprintf(sPath, "%s\\%s", path, fdFile.cFileName);
			if (!(fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY))
			{
				char *filename = strdup(sPath);
				list_append(files, &filename);
			}
		}
	}
	while (FindNextFile(hFind, &fdFile));

	FindClose(hFind);
#else
	DIR *d = opendir(path);
	struct dirent *dir;

	if (d == NULL)
		return NULL;

	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_type == DT_REG)
		{
			sPath[0] = '\0';
			strcat(sPath, path);
			strcat(sPath, "/");
			strcat(sPath, dir->d_name);
			char *filename = strdup(sPath);
			list_append(files, &filename);
		}
	}

	closedir(d);
#endif

	return files;
}
