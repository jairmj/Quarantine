#pragma once
#include "Personaje.h"
#include "Proyectil.h"

using namespace std;
class Jugador :	public Personaje
{
private:
	int puntos;
public:
	Proyectil** arreglo_proyectiles;
	Jugador();
	Jugador(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Jugador();

	void añadir_10puntos();
	int retornar_puntos();


	void caminar(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles, int mapa_principal);
	void mover_proyectiles(Graphics^ g, Bitmap^ img_bala);
	void disparar();
	bool determinar_disponibilidad_posicion(int x, int y, int direccion, int mapa_principal);
};

