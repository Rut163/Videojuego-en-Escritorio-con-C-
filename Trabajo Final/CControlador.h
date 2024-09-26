#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"CAliado.h"
#include"CLider.h"
#include"CHabitante.h"
#include"CAgente.h"
#include"CTanque.h"

using namespace System::Drawing;
class CControlador {
private:
	vector<CAliado*>ArrayAliados;
	vector<CHabitante*>ArrayHabitantes;
	vector<CAgente*>ArrayAgentes;
	CLider* ObjetoLider;
	Tanque* objTanque;
	int NumHabitantes, NumAgentes, NumAliados, tiempo, nivel, puntaje;
	bool mueveAgente;
public:
	CControlador(Bitmap^ bmpLider, Bitmap^ bmpAliados, Bitmap^ bmpHabitantes, Bitmap^ bmpAgentes, Bitmap^ bmpTanque, Bitmap^ bmpMolesto, int tiempo, int aliados, int agentes, int habitantes, int nivel) {
		this->NumHabitantes = habitantes;
		this->NumAgentes = agentes;
		this->NumAliados = aliados;
		this->tiempo = tiempo;
		this->nivel = nivel;
		mueveAgente = true;
		puntaje = 0;
		if (nivel == 1) ObjetoLider = new CLider(bmpLider->Width / 3, bmpLider->Height / 4, 1.0, nivel);
		if (nivel == 2) ObjetoLider = new CLider(bmpLider->Width / 3, bmpLider->Height / 4, 1.2, nivel);
		for (int i = 0; i < NumHabitantes; i++) {
			ArrayHabitantes.push_back(new CHabitante(bmpHabitantes->Width / 3, bmpHabitantes->Height / 4, 1.0));
		}
		for (int i = 0; i < NumAgentes; i++) {
			switch (nivel) {
			case 1:
				ArrayAgentes.push_back(new CAgente(bmpAgentes->Width / 5, bmpAgentes->Height / 4, 0.7));
				break;
			case 2:
				ArrayAgentes.push_back(new CAgente(bmpAgentes->Width / 4, bmpAgentes->Height / 4, 1.0));
				break;
			}
		}
		if (nivel == 2) objTanque = new Tanque(bmpTanque->Width / 3, bmpTanque->Height / 4, 1.0);
	}
	~CControlador() {}

	void AddAliado(int width, int height) {
		ArrayAliados.push_back(new CAliado(width, height, 1.0));
	}

	void DibujarTodo(Graphics^ g, Bitmap^ bmpLider, Bitmap^ bmpAliados, Bitmap^ bmpHabitantes, Bitmap^ bmpAgentes, Bitmap^ bmpTanque, Bitmap^ bmpMolesto) {
		if (ArrayAliados.size() != 0) {
			for (int i = 0; i < ArrayAliados.size(); i++) {
				if (ArrayAliados[i]->getVisible())
					ArrayAliados[i]->dibujar(g, bmpAliados);
			}
		}
		for (int j = 0; j < ArrayHabitantes.size(); j++) {
			ArrayHabitantes[j]->dibujar(g, bmpHabitantes);
			if (!mueveAgente && nivel == 2) {
				g->DrawImage(bmpMolesto, ArrayHabitantes[j]->getX(), ArrayHabitantes[j]->getY(), 20, 20);
			}
		}
		for (int i = 0; i < ArrayAgentes.size(); i++) {
			if (mueveAgente)
				ArrayAgentes[i]->dibujar(g, bmpAgentes);
		}
		ObjetoLider->dibujar(g, bmpLider);
		if (nivel == 2 && !mueveAgente)objTanque->dibujar(g, bmpTanque);
	}

	void MoverTodo(Graphics^ g) {
		if (ArrayAliados.size() != 0) {
			for (int i = 0; i < ArrayAliados.size(); i++) {
				if (ArrayAliados[i]->getDioSuministros()) {
					ArrayAliados[i]->move(g);
				}
				else if (!ArrayAliados[i]->getDioSuministros()) {
					if (ArrayAliados.size() > ArrayHabitantes.size()) {
						if (i < ArrayHabitantes.size()) {
							ArrayAliados[i]->BuscarHabitante(ArrayHabitantes[i]);
						}
						if (i >= ArrayHabitantes.size()) {
							ArrayAliados[i]->setDioSuministros(true);
						}
					}
					if (ArrayAliados.size() <= ArrayHabitantes.size()) {
						ArrayAliados[i]->BuscarHabitante(ArrayHabitantes[i]);
					}
				}

			}
		}

		for (int i = 0; i < ArrayHabitantes.size(); i++) {
			ArrayHabitantes[i]->Mover(g);
		}
		for (int i = 0; i < ArrayAgentes.size(); i++) {
			if (ArrayAgentes[i]->getVerificaAliado()) {
				if (mueveAgente) {
					ArrayAgentes[i]->BuscarAliado(ArrayAliados[i]);
				}
				else if (!mueveAgente) {
					//Nada. No hay. No existe
				}

			}
			else if (!ArrayAgentes[i]->getVerificaAliado() && mueveAgente)
				ArrayAgentes[i]->move(g);
		}
		if (nivel == 2 && !mueveAgente)objTanque->mover(g);
	}

	void verificarAliados() {
		if (ArrayAliados.size() > 0) {
			if (ArrayAliados.size() > ArrayAgentes.size()) {
				for (int i = 0; i < ArrayAgentes.size(); i++)
				{
					ArrayAgentes[i]->setVerificaAliado(true);
				}

			}
			else if (ArrayAliados.size() == ArrayAgentes.size()) {
				for (int i = 0; i < ArrayAgentes.size(); i++)
				{
					ArrayAgentes[i]->setVerificaAliado(true);
				}
			}
			else if (ArrayAliados.size() < ArrayAgentes.size()) {
				for (int i = 0; i < ArrayAliados.size(); i++)
				{
					ArrayAgentes[i]->setVerificaAliado(true);
				}
			}
		}
	}
	void Colision(Graphics^ g, Bitmap^ lapida) {
		if (ArrayAliados.size() > 0 && mueveAgente) {
			for (int i = 0; i < ArrayAliados.size(); i++) {
				for (int j = 0; j < ArrayAgentes.size(); j++) {
					if (ArrayAgentes[j]->getRectangle().IntersectsWith(ArrayAliados[i]->getRectangle())) {
						NumAliados-=1;
						if (puntaje - 5 < 0) puntaje = 0;
						else puntaje -= 5;
						if (ArrayAgentes.size() < ArrayAliados.size()) {
							ArrayAliados[i]->setVisible(false);
						}
						else {
							if (ArrayAgentes.size() >= ArrayAliados.size()) {
								if (j == ArrayAliados.size() - 1 && i == ArrayAliados.size() - 1) {
									ArrayAliados[i]->setVisible(false);
									ArrayAgentes[j]->setVerificaAliado(false);
								}
								else {
									ArrayAliados[i]->setVisible(false);
									ArrayAgentes[ArrayAliados.size() - 1]->setVerificaAliado(false);
								}
							}
						}
					}
				}
			}

		}

		//Eliminación
		if (ArrayAliados.size() > 0) {
			for (int i = 0; i < ArrayAliados.size(); i++) {
				if (!ArrayAliados[i]->getVisible()) {
					Rectangle sectionShown = Rectangle(0 * lapida->Width, 0 * lapida->Height, lapida->Width, lapida->Height);
					Rectangle zoom = Rectangle(ArrayAliados[i]->getX(), ArrayAliados[i]->getY(), lapida->Width * 0.8, lapida->Height * 0.8);
					g->DrawImage(lapida, zoom, sectionShown, GraphicsUnit::Pixel);
					ArrayAliados.erase(ArrayAliados.begin() + i);
					
				}
			}
		}

	}
	void ColisionAliadoHabitante(Graphics^ g, Bitmap^ bmpSuministro,int r) {
		for (int i = 0; i < ArrayAliados.size(); i++)
		{
			for (int j = 0; j < ArrayHabitantes.size(); j++)
			{
				if (ArrayAliados[i]->getRectangle().IntersectsWith(ArrayHabitantes[j]->getRectangle())) {
					ArrayAliados[i]->setDioSuministros(true);
					g->DrawImage(bmpSuministro, ArrayAliados[i]->getX(), ArrayAliados[i]->getY(), 50, 50);
					if (nivel == 2 && r == 2) {
						puntaje += 0;
						Rectangle sectionShown = Rectangle(0 * bmpSuministro->Width, 0 * bmpSuministro->Height, bmpSuministro->Width, bmpSuministro->Height);
						Rectangle zoom = Rectangle(ArrayAliados[i]->getX(), ArrayAliados[i]->getY(), bmpSuministro->Width * 0.5, bmpSuministro->Height * 0.5);
						g->DrawImage(bmpSuministro, zoom, sectionShown, GraphicsUnit::Pixel);
					}
					else{
						puntaje += 10;
					}
					ArrayAliados[i]->VolverAUbicación();
				}
			}
		}
	}
	void bajarPuntaje() {
		puntaje -= 10;
		if (puntaje < 0)puntaje = 0;
	}
	void repartirSuministros() {
		for (int i = 0; i < ArrayAliados.size(); i++)
		{
			ArrayAliados[i]->setDioSuministros(false);
		}
	}
	int get_numAliados() { return NumAliados; }
	void DisminuirTiempo() { tiempo--; }
	int get_tiempo() { return tiempo; }
	int get_puntaje() { return puntaje; }
	bool getMueveAgente() { return mueveAgente; }
	void setMueveAgente(bool p) { mueveAgente = p; }
	CLider* getLider() { return ObjetoLider; }
};