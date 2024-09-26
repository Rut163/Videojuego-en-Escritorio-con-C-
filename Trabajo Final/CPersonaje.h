#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;
enum Direcciones { Arriba, Abajo, Derecha, Izquierda };

class CPersonaje {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idx, idy;
	float z;
	bool visible;
public:
	CPersonaje(int width, int height, float zoom) {
		this->width = width;
		this->height = height;
		this->z = zoom;
		idx = idy = 0;
		visible = true;
	}

	~CPersonaje() {}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * z, height * z);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}
	int getX() { return x; }
	int getY() { return y; }
	void setx(float auX) { x = auX; }
	void setY(float auY) { y = auY; }
	Rectangle getRectangle() { return Rectangle(x, y, width * z, height * z); }
	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
};