#pragma once
#include"CPersonaje.h"
#include "CAliado.h"

class CAgente : public CPersonaje {
private:
	bool verificaAliado;
	int direccion;
public:
	CAgente(int width, int height, float zoom) : CPersonaje(width, height, zoom) {
		x = (rand() % 100 + 50) * 5;
		y = (rand() % 80 + 20) * 5;
		direccion = rand() % 2;
		dx = dy = 4;
		verificaAliado = false;
	}

	~CAgente() {}

	virtual void move(Graphics^ canva) {
		if (x < 0 || x + width * z > canva->VisibleClipBounds.Width)dx *= -1;
		if (y< 0 || y + height * z >canva->VisibleClipBounds.Height)dy *= -1;
		switch (direccion) {
		case 0:
			//Vertical:
			dx = 0;
			if (dy > 0)idy = 0;
			else idy = 1;
			y += dy;

			break;
		case 1:
			//Horizontal
			dy = 0;
			if (dx > 0)idy = 3;
			else idy = 2;
			x += dx;
			break;
		}

		idx++;
		if (idx > 3)idx = 0;

	}

	void setVerificaAliado(bool siHayAliado) {
		verificaAliado = siHayAliado;
	}

	bool getVerificaAliado() {
		return verificaAliado;
	}

	void BuscarAliado(CAliado* aliado) {
		dx = dy = 4;
		if (x == aliado->getX()) {
			x += 0;
		}
		else if (x > aliado->getX()) {
			x -= dx;
			idy = 2;
		}
		else if (x < aliado->getX()) {
			x += dx;
			idy = 3;
		}
		if (y == aliado->getY()) {
			y += 0;
		}
		else if (y > aliado->getY()) {
			y -= dy;
			idy = 1;
		}
		else if (y < aliado->getY()) {
			y += dy;
			idy = 0;
		}
		idx++;
		if (idx > 3)idx = 0;

	}

};