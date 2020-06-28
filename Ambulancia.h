#pragma once
#include "Personaje.h"
#include "Adversario.h"
class Ambulancia :	public Personaje{
public:
	int numero_objetivo;
	int aparicion_aleatoria;
	bool activado;
	Ambulancia();
	Ambulancia(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Ambulancia();

	void mover(Graphics^ g, Bitmap^ img_ambulancia, Adversario** arreglo_adversarios, int cantidad_adversarios);
};

