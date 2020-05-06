#ifndef PACMAN_POS_H
#define PACMAN_POS_H

typedef struct _Pos {
	int x;
	int y;
} Pos;

Pos *new_pos(void);
Pos *new_pos_init(int x, int y);
int get_pos_x(Pos *pos);
int get_pos_y(Pos *pos);
void set_pos_x(Pos *pos, int x);
void set_pos_y(Pos *pos, int y);
void set_pos(Pos *pos, int x, int y);
void update_pos_x(Pos *pos, int amount);
void update_pos_y(Pos *pos, int amount);
void update_pos(Pos *pos, int x_amount, int y_amount);
void free_pos(Pos *pos);

#endif // PACMAN_POS_H
