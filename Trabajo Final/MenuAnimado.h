#pragma once
using namespace System::Drawing;
class MovingMap {

private:
	int x, y;
	int width, height;
	int idx, idy;
	int numFrames;
	double z;

public:
	MovingMap(int x, int y, int alto, int ancho, int numFrames, double z) {
		width = ancho;
		height = alto;
		idx = idy = 0;
		this->x = x;
		this->y = y;
		this->numFrames = numFrames;
		this->z = z;
	}
	~MovingMap() {}

	void dibujar(Graphics^ canva, Bitmap^ fondo) {
		Rectangle seccion = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * z, height * z);
		canva->DrawImage(fondo, zoom, seccion, GraphicsUnit::Pixel);
	}

	void anima() {
		idx++;
		if (idx > numFrames)idx = 0;
	}
};