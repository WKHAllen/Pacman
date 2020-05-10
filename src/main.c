#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "game.h"
#include "readdir.h"
#include "../bin/include/list.h"

#define MAP_DIR "map"

void clear_screen(void)
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int get_int(int *result)
{
	int ret_code = scanf("%d", result);

	if (ret_code == EOF)
		return FAILURE_CODE;
	if (ret_code == 0)
	{
		while (fgetc(stdin) != '\n') {}
		return FAILURE_CODE;
	}

	return SUCCESS_CODE;
}

int selection(const char *prompt, int num_options, const char **options)
{
	printf("%s\n\n", prompt);
	for (int i = 0; i < num_options; i++)
		printf("%4d. %s\n", i + 1, options[i]);

	printf("\n> ");
	int choice = 0;
	int ret_code = get_int(&choice);
	while (ret_code == FAILURE_CODE || choice < 1 || choice > num_options)
	{
		printf("Please enter an integer between 1 and %d.\n> ", num_options);
		ret_code = get_int(&choice);
	}

	return choice;
}

char *select_map(char *map_dir)
{
	List *files = list_files(map_dir);
	if (files == NULL || list_size(files) == 0)
		return "";
	int num_files = list_size(files);

	printf("Select a map:\n\n");
	for (int i = 0; i < num_files; i++)
		printf("%4d. %s\n", i + 1, *(char **)list_get(files, i));

	printf("\n> ");
	int choice = 0;
	int ret_code = get_int(&choice);
	while (ret_code == FAILURE_CODE || choice < 1 || choice > num_files)
	{
		printf("Please enter an integer between 1 and %d.\n> ", num_files);
		ret_code = get_int(&choice);
	}

	char *chosen_file = strdup(*(char **)list_get(files, choice));
	for (int i = 0; i < num_files; i++)
		free(*(char **)list_get(files, i));
	list_free(files);
	return chosen_file;
}

void play(char *map_file)
{
	// TODO: start game
}

void pause(char *prompt)
{
	int ch;
	do
		ch = fgetc(stdin);
	while (ch != EOF && ch != '\n');
	clearerr(stdin);
	printf("%s", prompt);
	fflush(stdout);
	getchar();
}

int main(int argc, char **argv)
{
	int done = 0;
	do
	{
		clear_screen();
		printf("        P A C M A N        \n\n");

		const char *options[] = {"Play the game", "Make/edit a map", "Quit"};
		int selected = selection("Welcome to Pacman! What would you like to do?", sizeof(options) / sizeof(options[0]), options);
		clear_screen();

		switch (selected)
		{
			case 1: ;
				char *map_file = select_map(MAP_DIR);
				if (map_file[0] == '\0')
					pause("\nNo map files found. Press enter to return to the menu.");
				else
				{
					play(map_file);
					free(map_file);
				}
				break;
			case 2:
				// TODO: launch map editor
				break;
			case 3:
				done = 1;
				break;
		}
	}
	while (done == 0);

	printf("\nThanks for playing!\n");
	return 0;
}
