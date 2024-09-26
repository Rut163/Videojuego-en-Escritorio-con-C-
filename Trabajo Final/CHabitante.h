#pragma once
#include"CPersonaje.h"

class CHabitante :public CPersonaje {
private:
	int posFinalx;
	int posFinaly;
public:
	CHabitante(int Width, int Height, float zoom) : CPersonaje(Width, Height, zoom) {
		this->width = Width;
		this->height = Height;
		dx = dy = 1;
		idx = idy = 0;
		x = (rand() % 2) * 900;
		y = rand() % 500 + 1;
		posFinalx = rand() % 950 + 1;
		posFinaly = rand() % 480 + 2;
	}
	~CHabitante() {}
	void Mover(Graphics^ g) {
		if (x < posFinalx) {
			x += dx;
			idy = 2;
		}
		if (x > posFinalx) {
			x -= dx;
			idy = 1;
		}
		if (y < posFinaly) {
			y += dx;
			idy = 0;
		}
		if (y > posFinaly) {
			y -= dy;
			idy = 3;
		}
		idx++;
		if (idx > 2)idx = 0;
		if (x == posFinalx && y == posFinaly) {
			dx = dy = 0;
			idx = idy = 0;
		}
	}
};