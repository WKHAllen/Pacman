#include <stdlib.h>
#include "pos.h"

Pos *new_pos(void)
{
	return new_pos_init(0, 0);
}

Pos *new_pos_init(int x, int y)
{
	Pos *pos = malloc(sizeof(*pos));
	pos->x = 0;
	pos->y = 0;
	return pos;
}

int get_pos_x(Pos *pos)
{
	return pos->x;
}

int get_pos_y(Pos *pos)
{
	return pos->y;
}

void set_pos_x(Pos *pos, int x)
{
	pos->x = x;
}

void set_pos_y(Pos *pos, int y)
{
	pos->y = y;
}

void set_pos(Pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

void free_pos(Pos *pos)
{
	free(pos);
}
