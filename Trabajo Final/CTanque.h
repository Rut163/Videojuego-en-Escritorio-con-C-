#pragma once
#include "CPersonaje.h"

class Tanque : public CPersonaje {
public:
	Tanque(int width, int height, float zoom) :CPersonaje(width, height, zoom)
	{
		x = 0;
		y = 1;
		idx = 0;
		idy = 2;
		dx = 5;
		dy = 0;
	}
	~Tanque() {}
	void mover(Graphics^ g)
	{
		x += dx; y += dy;
		idx++;
		if (idx == 3)idx = 0;
		if (x + dx + width >= g->VisibleClipBounds.Width)
		{
			dx = 0;
			dy = 5;
			idy = 0;
		}
		if (x + dx <= 0)
		{
			dx = 0;
			dy = -5;
			idy = 3;
		}
		if (y + dy + height >= g->VisibleClipBounds.Height)
		{
			dx = -5;
			dy = 0;
			idy = 1;
		}
		if (y + dy <= 0)
		{
			dx = 5;
			dy = 0;
			idy = 2;
		}
	}

};