#pragma once
#include "CPersonaje.h"
#include"CHabitante.h"
class CAliado : public CPersonaje {
protected:
	int direccion;
	bool dioSuministros;
public:
	CAliado(int width, int height, float zoom) : CPersonaje(width, height, zoom) {
		dx = dy = 4;
		x = rand() % 800;
		y = 400;
		direccion = rand() % 2;
		dioSuministros = false;
	}
	~CAliado() {}
	void move(Graphics^ g) {
		switch (direccion) {
		case 0: //Horizontal
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) {
				idy = 2;
			}
			else {
				idy = 1;
			}
			x += dx;
			break;
		case 1: //Vertical
			if (y + height * 1.0 >= g->VisibleClipBounds.Height || y < 0)dy *= -1;
			if (dy > 0) {
				idy = 0;
			}
			else {
				idy = 3;
			}
			y += dy;
			break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}

	void setDioSuministros(bool evento) {
		dioSuministros = evento;
	}

	bool getDioSuministros() {
		return dioSuministros;
	}

	void BuscarHabitante(CHabitante* habitante) {
		dx = dy = 4;
		if (x == habitante->getX()) {
			x += 0;
		}
		else if (x > habitante->getX()) {
			x -= dx;
			idy = 1;
		}
		else if (x < habitante->getX()) {
			x += dx;
			idy = 2;
		}
		if (y == habitante->getY()) {
			y += 0;
		}
		else if (y > habitante->getY()) {
			y -= dy;
			idy = 3;
		}
		else if (y < habitante->getY()) {
			y += dy;
			idy = 0;
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	void VolverAUbicación() {
		x = rand() % 900 + 11; y = rand() % 500 + 5;
	}

};