#pragma once
#include "Personaje.h"
#include "Proyectil.h"

using namespace std;
class Jugador :	public Personaje
{
private:
public:
	Proyectil** arreglo_proyectiles;
	Jugador();
	Jugador(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Jugador();

	void caminar(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles);
	void mover_proyectiles(Graphics^ g, Bitmap^ img_bala);
	void disparar();
	bool determinar_disponibilidad_posicion(int x, int y, int direccion);
};

