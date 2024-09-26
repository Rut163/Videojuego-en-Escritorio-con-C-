#pragma once
#include"CPersonaje.h"

class CLider : public CPersonaje {
private:
	int nivel;
public:
	CLider(int width, int height, float zoom, int nivel) : CPersonaje(width, height, zoom) {
		this->width = width;
		this->height = height;
		this->z = zoom;
		this->nivel = nivel;
		x = 200;
		y = 200;
		dx = dy = 6;
		idx = idy = 0;
	}
	~CLider() {}
	void mover(Graphics^ g, Direcciones direccion) {
		switch (nivel) {
		case 1:
			switch (direccion) {
			case Arriba:
				if (y > 0) {
					y -= dy;
					idy = 3;
				}
				break;
			case Abajo:
				if (y + height * z < g->VisibleClipBounds.Height) {
					y += dy;
					idy = 0;
				}
				break;
			case Derecha:
				if (x + width * z < g->VisibleClipBounds.Width) {
					x += dx;
					idy = 2;
				}
				break;
			case Izquierda:
				if (x > 0) {
					x -= dx;
					idy = 1;
				}
				break;
			}
			idx++;
			if (idx > 2)idx = 0;
			break;
		case 2:
			switch (direccion) {
			case Arriba:
				if (y > 0) {
					y -= dy;
					idy = 1;
				}
				break;
			case Abajo:
				if (y + height * z < g->VisibleClipBounds.Height) {
					y += dy;
					idy = 0;
				}
				break;
			case Derecha:
				if (x + width * z < g->VisibleClipBounds.Width) {
					x += dx;
					idy = 3;
				}
				break;
			case Izquierda:
				if (x > 0) {
					x -= dx;
					idy = 2;
				}
				break;
			}
			idx++;
			if (idx > 2)idx = 0;
			break;
		}
	}
};