#include "pos.h"

Pos::Pos() {
	Pos(0, 0);
}

Pos::Pos(int x, int y) {
	_x = x;
	_y = y;
}

int Pos::getX() {
	return _x;
}

int Pos::getY() {
	return _y;
}

void Pos::setX(int x) {
	_x = x;
}

void Pos::setY(int y) {
	_y = y;
}

void Pos::setPos(int x, int y) {
	_x = x;
	_y = y;
}

void Pos::updateX(int amount) {
	_x += amount;
}

void Pos::updateY(int amount) {
	_y += amount;
}

void Pos::updatePos(int x_amount, int y_amount) {
	_x += x_amount;
	_y += y_amount;
}
