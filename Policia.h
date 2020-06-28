#pragma once
#include "Personaje.h"
#include "Ambulancia.h"
class Policia :	public Personaje{

public:
	Policia();
	Policia(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Policia();
	

	void mover(Graphics^ g, Bitmap^ img_policia, Adversario** arreglo_adversarios, int cantidad_adversarios);

	int numero_objetivo;
};

