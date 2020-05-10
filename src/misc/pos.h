#ifndef PACMAN_POS_H
#define PACMAN_POS_H

class Pos {
	private:
		int _x;
		int _y;

	public:
		Pos();
		Pos(int x, int y);
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
		void setPos(int x, int y);
		void updateX(int amount);
		void updateY(int amount);
		void updatePos(int x_amount, int y_amount);
};

#endif // PACMAN_POS_H
