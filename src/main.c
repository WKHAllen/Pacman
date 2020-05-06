#include <stdio.h>
#include <stdlib.h>
#include "game.h"

#define SUCCESS_CODE 0
#define FAILURE_CODE 1

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

void play(void)
{
	// TODO: add map selection
	// TODO: start game
}

int main(int argc, char **argv)
{
	clear_screen();
	printf("        P A C M A N        \n\n");

	const char *options[] = {"Play the game", "Make/edit a map"};
	int selected = selection("Welcome to Pacman! What would you like to do?", 2, options);

	switch (selected)
	{
		case 1:
			play();
			break;
		case 2:
			// TODO: launch map editor
			break;
	}

	printf("Thanks for playing!\n");
	return 0;
}
